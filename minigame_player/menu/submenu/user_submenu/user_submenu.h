#pragma once

#include "menu/menu.h"

class UserSubmenu : public Menu {
public:
    UserSubmenu();

    void user_load_menu();

    void guest_load_menu();

    void show_guest();

    void show_user(UserData *);

    std::string get_name() override { return "user_bar"; };
private:
    tgui::Group::Ptr guest;
    tgui::Group::Ptr user;

    UserData *user_data;
};
