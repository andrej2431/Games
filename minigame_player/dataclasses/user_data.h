#pragma once

#include "data_header.h"

struct UserData {
    UserData(int new_id, std::string new_username, std::string new_password_hash) : user_id(new_id),
                                                                                    username(std::move(
                                                                                            new_username)),
                                                                                    password_hash(std::move(
                                                                                            new_password_hash)) {}

    UserData() : UserData(0, "", "") {}

    int user_id;
    std::string username;
    std::string password_hash;
};

struct LoginCredentials {
    std::string username;
    std::string password;
};

struct RegisterCredentials {
    std::string username;
    std::string password1;
    std::string password2;
};
