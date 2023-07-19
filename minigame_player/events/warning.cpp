#include "warning.h"

const std::string &Warning::get_message(int warning_number) {
    static std::map<int, std::string> warning_map = {
            {NONE,                      ""},
            {BAD_CHARACTERS_USERNAME,   "Username must be of length at least 4 with only letters and numbers!"},
            {BAD_CHARACTERS_PASSWORD,   "Password must be of length at least 4 with only letters and numbers!"},
            {INVALID_USERNAME_PASSWORD, "Invalid username/password!"},
            {PASSWORDS_NOT_MATCHING,    "Passwords must match!"},
            {USERNAME_TAKEN,            "Username is taken, please use another one!"},
            {GAME_CRASHED,              "Game crashed, please inform the developer."}};
    return warning_map[warning_number];
}