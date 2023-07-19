#include "tile.h"

using namespace match_pairs;

Tile::Tile(sf::Color new_color, float new_size) {
    color = new_color;
    back_color = sf::Color(180, 180, 180);

    rect = sf::RectangleShape(sf::Vector2(new_size, new_size));
    rect.setFillColor(back_color);
    facing_down = true;
}

bool Tile::position_in_rect(Vector2d position) {
    return rect.getGlobalBounds().contains(position.x, position.y);
}

void Tile::turn_over() {
    facing_down = !facing_down;
    if (facing_down)
        rect.setFillColor(back_color);
    else
        rect.setFillColor(color);

}