#include "user_controller.h"

void UserController::user_login(const LoginCredentials &login_credentials) {
    std::string username = login_credentials.username, password = login_credentials.password;
    if (!valid_username(username)) {
        raise_event(Event(Event::WARNING, Warning::BAD_CHARACTERS_USERNAME));
        return;
    }

    if (!valid_password(password)) {
        raise_event(Event(Event::WARNING, Warning::BAD_CHARACTERS_PASSWORD));
        return;
    }

    UserData user = DatabaseManager::get_user(username, password);

    if (user.user_id == 0) {
        raise_event(Event(Event::WARNING, Warning::INVALID_USERNAME_PASSWORD));
        return;
    }

    session->user = user;


}

void UserController::user_register(const RegisterCredentials &register_credentials) {
    std::string username = register_credentials.username,
            password1 = register_credentials.password1, password2 = register_credentials.password2;

    if (!valid_username(username)) {
        raise_event(Event(Event::WARNING, Warning::BAD_CHARACTERS_USERNAME));
        return;
    }

    if (!valid_password(password1) || !valid_password(password2)) {
        raise_event(Event(Event::WARNING, Warning::BAD_CHARACTERS_PASSWORD));
        return;
    }

    if (password1 != password2) {
        raise_event(Event(Event::WARNING, Warning::PASSWORDS_NOT_MATCHING));
        return;
    }

    if (DatabaseManager::get_user(username).user_id != 0) {
        raise_event(Event(Event::WARNING, Warning::USERNAME_TAKEN));
        return;
    }


    DatabaseManager::add_user(username, password1);
    session->user = DatabaseManager::get_user(username);
}

void UserController::join_as_guest() {
    session->user = UserData();

}

void UserController::log_out() {
    session->user = UserData();
}

bool UserController::valid_username(const std::string &username) {
    const std::regex username_regex("^[a-zA-Z0-9_]{4,30}$");
    if (std::regex_match(username, username_regex))
        return true;
    else
        return false;
}

bool UserController::valid_password(const std::string &password) {
    const std::regex password_regex("^[a-zA-Z0-9_]{4,30}$");
    if (std::regex_match(password, password_regex))
        return true;
    else
        return false;
}
