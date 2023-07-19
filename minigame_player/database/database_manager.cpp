#include "database_manager.h"


void DatabaseManager::add_user(const std::string &username, const std::string &password) {
    Json::Value *json_user_list = get_table_json("users");
    int new_user_id = (int) json_user_list->size();

    UserData new_user = UserData(new_user_id, username, hash(password));
    Json::Value *json_new_user = user_to_json(new_user);

    json_user_list->append(*json_new_user);
    write_to_table("users", *json_user_list);

    delete json_user_list;
    delete json_new_user;
}

UserData DatabaseManager::get_user(const std::string &username) {
    Json::Value *json_user_list = get_table_json("users");

    Json::Value json_user = get_list_entry(*json_user_list, "username", username);

    return json_to_user(json_user);
}

UserData DatabaseManager::get_user(const std::string &username, const std::string &password) {
    Json::Value *json_user_list = get_table_json("users");
    Json::Value json_user = get_list_entry(*json_user_list, "username", username);

    if (json_user["password_hash"].asString() != hash(password))
        return {};

    return json_to_user(json_user);
}

int DatabaseManager::get_high_score(unsigned int user_id, const std::string &game) {
    Json::Value *json_high_score_list = get_table_json("highscores");
    Json::Value user_high_scores = get_list_entry(*json_high_score_list, "user_id", user_id);

    return user_high_scores["high_scores"][game].asInt();
}

void DatabaseManager::save_high_score(unsigned int user_id, const std::string &game, int value) {
    if (user_id == 0)
        return;
    std::vector<std::string> games = {"snake", "match_pairs", "simon_says", "tic_tac_toe"};
    if (std::find(games.cbegin(), games.cend(), game) == games.cend())
        return;
    Json::Value *json_high_score_list = get_table_json("highscores");

    for (auto &user_info: *json_high_score_list) {
        if (user_info["user_id"].asInt() == user_id) {
            if (user_info["high_scores"][game].asInt() < value)
                user_info["high_scores"][game] = value;
            write_to_table("highscores", *json_high_score_list);
            return;
        }
    }
    auto user_entry = Json::Value();
    auto scores_entry = Json::Value();
    user_entry["user_id"] = user_id;
    user_entry["high_scores"] = scores_entry;
    for (const std::string &game_name: games)
        user_entry["high_scores"][game_name] = 0;
    user_entry["high_scores"][game] = value;
    json_high_score_list->append(user_entry);
    write_to_table("highscores", *json_high_score_list);
}

LeaderboardData DatabaseManager::get_leaderboard(const std::string &game_name) {
    Json::Value *json_high_score_list = get_table_json("highscores");
    Json::Value *json_user_list = get_table_json("users");
    return json_to_leaderboard(*json_user_list, *json_high_score_list, game_name);
}