#pragma once

#include "games/game.h"

namespace match_pairs {
    using GameVectors::Vector2d;

    class Tile {
    public:
        Tile(sf::Color, float);

        sf::RectangleShape &get_rect() { return rect; };

        bool position_in_rect(Vector2d);

        bool is_facing_down() const { return facing_down; };

        void turn_over();

        sf::Color get_color() { return color; };

    private:
        sf::Color color, back_color;
        sf::RectangleShape rect;
        bool facing_down;
    };
}