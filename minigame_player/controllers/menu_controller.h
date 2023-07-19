#pragma once

#include <regex>
#include "game_controller.h"
#include "menu/login_menu.h"
#include "menu/register_menu.h"
#include "menu/main_menu.h"
#include "menu/notification_menu.h"
#include "database/database_manager.h"
#include "games/game.h"


class MenuController {

public:

    explicit MenuController(sf::RenderWindow *, SessionData *);

    void handle_input(sf::Event &input);

    LoginCredentials get_login_credentials();

    RegisterCredentials get_register_credentials();

    void mainloop();

    void switch_to_menu(int);

    void start_game(int);

    void close_game();

    void raise_warning(int);

    void update_leaderboard(const std::string &);

private:
    GameController *game_controller;

    Menu *get_menu(int);

    SessionData *session;

    tgui::Gui *gui;

    NotificationMenu *notification_menu;
    LoginMenu *login_menu;
    RegisterMenu *register_menu;
    MainMenu *main_menu;
};
