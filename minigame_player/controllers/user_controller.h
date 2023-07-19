#pragma once

#include "dataclasses/dataclasses.h"
#include "database/database_manager.h"
#include "events/event_stream.h"
#include <TGUI/TGUI.hpp>


class UserController {
public:
    explicit UserController(SessionData *new_session) : session(new_session) {};

    void user_login(const LoginCredentials &);

    void user_register(const RegisterCredentials &);

    void join_as_guest();

    void log_out();

    static bool valid_username(const std::string &);

    static bool valid_password(const std::string &);

private:
    SessionData *session;
};

