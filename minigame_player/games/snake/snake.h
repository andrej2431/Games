#pragma once

#include "games/game.h"
#include "games/snake/helper/state.h"
#include "games/snake/helper/entity.h"
#include "games/snake/skins/skin_manager.h"

#include <utility>

using namespace GameVectors;
namespace snake {
    class Snake : public Game {
    public:


        Snake(tgui::Group::Ptr, SessionData *);

        void handle_event(sf::Event &) override;

        void game_loop() override;

        void draw() override;

        std::string get_name() override { return "snake"; };


        ~Snake() override;


    private:
        void new_game();

        void game_over();


        float tile_size;

        State *state;
        SkinManager *skin_manager;
        sf::Sprite map_sprite;


    };

}