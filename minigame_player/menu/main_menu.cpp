#include "main_menu.h"

MainMenu::MainMenu() : Menu() {
    session = nullptr;
    main_submenu = new MainSubmenu();
    feats_submenu = new FeatsSubmenu();
    user_submenu = new UserSubmenu();

    menu->add(main_submenu->get());
    menu->add(feats_submenu->get());
    menu->add(user_submenu->get());
    hide();
}


void MainMenu::show_default_submenus() {
    main_submenu->show_default();
    if (session->user.user_id == 0)
        user_submenu->show_guest();
    else
        user_submenu->show_user(&session->user);
    user_submenu->show();
}