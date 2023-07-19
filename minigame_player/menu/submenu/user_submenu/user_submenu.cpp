#include "user_submenu.h"

UserSubmenu::UserSubmenu() : Menu() {
    guest = tgui::Group::create();
    user = tgui::Group::create();

    guest_load_menu();
    user_load_menu();

    menu->setSize("15%", "90%");
    menu->setPosition("84%", "5%");

    menu->add(guest, "guest_submenu");
    menu->add(user, "user_submenu");
}

void UserSubmenu::show_guest() {
    user->setVisible(false);
    guest->setVisible(true);
}

void UserSubmenu::show_user(UserData *new_user_data) {
    user_data = new_user_data;
    user->get<tgui::Label>("user_label")->setText(user_data->username);
    guest->setVisible(false);
    user->setVisible(true);
}