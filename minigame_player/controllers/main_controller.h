#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "game_controller.h"
#include "menu_controller.h"
#include "user_controller.h"
#include "database/database_manager.h"


class MainController {
public:
    MainController(sf::VideoMode, sf::Uint32);

    MainController() : MainController(sf::VideoMode::getDesktopMode(), sf::Style::Fullscreen) {};

    ~MainController();

private:
    void mainloop();

    void manage_input();

    void manage_events();

    void handle_event(Event &);


    SessionData *session;

    sf::VideoMode video_mode;
    sf::RenderWindow *window;

    UserController *user_controller;
    MenuController *menu_controller;
};