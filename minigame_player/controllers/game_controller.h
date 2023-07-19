#pragma once


#include "games/games_list.h"
#include "database/database_manager.h"
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "events/event_stream.h"


class GameController {
public:
    explicit GameController(tgui::Group::Ptr, SessionData *);

    void mainloop();

    void handle_input(sf::Event &);

    bool is_game_running();

    void start_game(int);

    void close_game();

private:
    SessionData *session;
    tgui::Group::Ptr menu;
    Game *running_game;

};