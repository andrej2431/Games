#pragma once

#include "data_header.h"

struct LeaderboardData {
    using score_type = std::pair<std::string, int>;

    LeaderboardData() = default;

    explicit LeaderboardData(std::vector<std::pair<std::string, int>> new_scores) : scores(std::move(new_scores)) {};
    std::vector<score_type> scores;
};