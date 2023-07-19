
#pragma once

#include <fstream>
#include  <iostream>
#include <functional>
#include <random>
#include "dataclasses/dataclasses.h"
#include <json/json.h>


class DatabaseManager {
public:
    DatabaseManager() = default;

    static void add_user(const std::string &, const std::string &);

    static UserData get_user(const std::string &);

    static UserData get_user(const std::string &, const std::string &);

    static void save_high_score(unsigned int, const std::string &, int);

    static int get_high_score(unsigned int, const std::string &);


    static LeaderboardData get_leaderboard(const std::string &);


private:

    static Json::Value get_list_entry(Json::Value &, const std::string &, const std::string &);

    static Json::Value get_list_entry(Json::Value &, const std::string &, unsigned int);

    static std::string hash(const std::string &text) { return std::to_string(std::hash<std::string>{}(text)); };

    static Json::Value *get_table_json(const std::string &);

    static void write_to_table(const std::string &, Json::Value &);

    static UserData json_to_user(Json::Value &);

    static Json::Value *user_to_json(UserData &);

    static LeaderboardData json_to_leaderboard(Json::Value &, Json::Value &, const std::string &);
};
