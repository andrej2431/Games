#pragma once

#include "menu.h"
#include "submenu/submenus_header.h"

class MainMenu : public Menu {
public:
    MainMenu();

    std::string get_name() override { return "main_menu"; };

    void show_default_submenus();

    void show() override {
        show_default_submenus();
        menu->setVisible(true);
    };

    SessionData *session;

    MainSubmenu *main_submenu;
    FeatsSubmenu *feats_submenu;
    UserSubmenu *user_submenu;
};