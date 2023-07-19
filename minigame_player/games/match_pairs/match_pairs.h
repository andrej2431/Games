#pragma once

#include "games/game.h"
#include "tile.h"
#include <utility>


using namespace GameVectors;
namespace match_pairs {

    class MatchPairs : public Game {
    public:
        MatchPairs(tgui::Group::Ptr, SessionData *);

        ~MatchPairs() override;

        void load_moves_label();

        void load_tiles();

        void shuffle_tiles();

        void press_tile(Tile &);

        void increase_score();

        void new_game();

        void handle_event(sf::Event &) override;

        void game_loop() override;

        void draw() override;

        std::string get_name() override { return "match_pairs"; };


        void game_over();


    private:
        bool playing = false;
        uint64_t tick = 61;
        int moves = 50, n_of_turned = 0;

        Tile *turned_over = nullptr, *turned_over_2 = nullptr;


        std::vector<Tile> tiles;

        tgui::Label::Ptr moves_label;
        tgui::Vector2f canvas_pos;


        float canvas_size = 0;
        float tile_size = 0;
        float padding = 0;


        std::vector<sf::Color> colors{
                {128, 0,   0},
                {170, 110, 40},
                {128, 128, 0},
                {0,   128, 128},
                {0,   0,   128},
                {230, 25,  75},
                {245, 130, 48},
                {255, 255, 25},
                {60,  180, 75},
                {70,  240, 240},
                {0,   130, 200},
                {145, 30,  180},
                {240, 50,  230},
                {255, 215, 180},
                {255, 250, 200},
                {170, 255, 195},
                {220, 190, 255},
                {128, 128, 128}
        };

    };
}