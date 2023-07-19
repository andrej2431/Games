#pragma once

#include "games/game.h"
#include "tile.h"

namespace tic_tac_toe {
    class TicTacToe : public Game {
    public:
        TicTacToe(tgui::Group::Ptr, SessionData *);

        ~TicTacToe() override;

        void handle_event(sf::Event &) override;

        void game_loop() override;

        void draw() override;

        std::string get_name() override { return "tic_tac_toe"; };


        void new_game();

        void load_labels();

        void load_tiles();

        void tile_clicked(int, int);

        void game_over();

        int game_result();

        void opponent_respond();

    private:
        void load_game_textures();

        bool playing = false;

        std::vector<std::vector<Tile>> tiles;
        sf::Texture p0_texture, p1_texture, empty_texture;
        tgui::Vector2f canvas_pos;
        tgui::Label::Ptr victory_label, draw_label;
        float canvas_size = 0;


    };

}