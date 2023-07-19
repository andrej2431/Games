#pragma once

#include "menu.h"


class LoginMenu : public Menu {
public:
    LoginMenu() : Menu() { load_menu(); };

    void load_menu();

    void hide() override;

    std::string get_name() override { return "login_menu"; };

};

