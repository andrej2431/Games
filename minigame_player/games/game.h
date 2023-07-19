#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <iostream>
#include <utility>
#include <deque>
#include <random>
#include "database/database_manager.h"
#include "vectors.h"


class Game {
public:
    Game(tgui::Group::Ptr, SessionData *);

    enum : int {
        NONE = 0,
        SNAKE = 1,
        SIMON_SAYS = 2,
        MATCH_PAIRS = 3,
        TIC_TAC_TOE = 4
    };

    virtual void handle_event(sf::Event &) = 0;

    virtual void game_loop() = 0;

    virtual void draw() = 0;

    virtual std::string get_name() = 0;

    void update_scores();

    void load_menu();

    virtual ~Game();

protected:
    int score = 0, high_score = 0;
    tgui::Group::Ptr menu;
    SessionData *session;
    tgui::CanvasSFML::Ptr canvas;
    tgui::Label::Ptr game_over_label, score_label, high_score_label;
};


inline void load_texture(const std::string &filename, sf::Texture &texture) {
    if (!texture.loadFromFile("../" + filename))
        throw std::invalid_argument("Couldn't load texture from file!");
}
