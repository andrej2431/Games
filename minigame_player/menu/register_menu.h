#pragma once

#include "menu.h"

class RegisterMenu : public Menu {
public:
    RegisterMenu() : Menu() { load_menu(); };

    void hide() override;

    void load_menu();

    std::string get_name() override { return "register_menu"; };
};

