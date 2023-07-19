#pragma once

#include <string>
#include <map>

namespace Warning {
    enum : int {
        NONE, BAD_CHARACTERS_USERNAME, BAD_CHARACTERS_PASSWORD, INVALID_USERNAME_PASSWORD,
        PASSWORDS_NOT_MATCHING, USERNAME_TAKEN, GAME_CRASHED
    };

    const std::string &get_message(int);
}