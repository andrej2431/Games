#pragma once

#include "games/game.h"

namespace tic_tac_toe {
    class Tile {
    public:
        Tile(float, float, float);

        void set_textures(sf::Texture *, sf::Texture *, sf::Texture *);

        int get_player() const { return taken_player_id; };

        void adjust_size();

        void set_player(int);

        sf::RectangleShape &get_rect() { return rect; };

        sf::Sprite &get_sprite() { return symbol_sprite; };
    private:

        float size;
        int taken_player_id = -1;
        sf::RectangleShape rect;
        sf::Texture *p0_texture = nullptr, *p1_texture = nullptr, *empty_texture = nullptr;
        sf::Sprite symbol_sprite;
    };

    inline bool operator==(Tile &t1, Tile &t2) { return t1.get_player() == t2.get_player(); }
}