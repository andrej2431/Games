#pragma once

#include "menu/menu.h"

class MainSubmenu : public Menu {
public:
    MainSubmenu();

    std::string get_name() override { return "user_bar"; };

    void load_library();

    void show_game();

    void show_default();

private:
    tgui::Group::Ptr library;

    std::map<std::string, sf::Texture> library_button_textures;
};

