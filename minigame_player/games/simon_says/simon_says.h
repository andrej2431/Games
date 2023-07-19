#pragma once

#include "games/game.h"
#include <utility>

namespace simon_says {
    using namespace GameVectors;

    class SimonSays : public Game {
    public:
        SimonSays(tgui::Group::Ptr, SessionData *);

        ~SimonSays() override;

        void load_tiles();

        void new_game();

        void handle_event(sf::Event &) override;

        void game_loop() override;

        void draw() override;

        std::string get_name() override { return "simon_says"; };

        void game_over(IntVector2d);

        void press_tile(IntVector2d);

        void activate_tile();

        void deactivate_tile();


    private:
        bool playing = false;
        uint64_t tick = 0, speed = 20;
        std::vector<std::vector<sf::RectangleShape>> tiles;


        std::vector<IntVector2d> pattern;
        bool showing_pattern = true;

        int activating_index = 0, deactivating_index = 0;

        tgui::Vector2f canvas_pos;

        float tile_size = 0;
        float padding = 0;


        std::vector<sf::Color> colors{
                {180, 0,   0},
                {0,   180, 0},
                {0,   0,   180},
                {180, 180, 0},

                {255, 0,   0},
                {0,   255, 0},
                {0,   0,   255},
                {255, 255, 0}
        };

    };
}