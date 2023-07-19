#include "main_submenu.h"

MainSubmenu::MainSubmenu() : Menu() {
    library = tgui::Group::create();

    load_library();

    menu->setSize("50%", "90%");
    menu->setPosition("1%", "5%");

    menu->add(library);
    hide();

}

void MainSubmenu::show_default() {
    library->setVisible(true);
    show();
}


void MainSubmenu::show_game() {
    library->setVisible(false);
}
