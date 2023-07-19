#include "database_manager.h"


UserData DatabaseManager::json_to_user(Json::Value &json_user) {
    UserData user;
    if (json_user.empty())
        return user;

    user.user_id = json_user["user_id"].asInt();
    user.username = json_user["username"].asString();
    user.password_hash = json_user["password_hash"].asString();
    return user;

}

Json::Value *DatabaseManager::user_to_json(UserData &user) {
    auto *json_user = new Json::Value();
    (*json_user)["user_id"] = user.user_id;
    (*json_user)["username"] = user.username;
    (*json_user)["password_hash"] = user.password_hash;
    return json_user;
}

LeaderboardData
DatabaseManager::json_to_leaderboard(Json::Value &user_list, Json::Value &score_list, const std::string &game_name) {
    std::map<int, LeaderboardData::score_type> score_map;
    for (auto &user_info: user_list)
        score_map[user_info["user_id"].asInt()] = {user_info["username"].asString(), 0};
    for (auto &user_score: score_list)
        score_map[user_score["user_id"].asInt()].second = user_score["high_scores"][game_name].asInt();
    std::vector<LeaderboardData::score_type> scores;
    scores.reserve(score_map.size());
    for (auto &item: score_map)
        if (item.first != 0)
            scores.push_back(item.second);
    std::sort(scores.begin(), scores.end(), [](LeaderboardData::score_type &s1,
                                               LeaderboardData::score_type &s2) { return s1.second > s2.second; });
    LeaderboardData leaderboard(scores);
    return leaderboard;
};
