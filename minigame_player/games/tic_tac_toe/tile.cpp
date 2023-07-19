#include "tile.h"

using namespace tic_tac_toe;

Tile::Tile(float new_x, float new_y, float new_size) {
    size = new_size;
    rect = sf::RectangleShape(sf::Vector2f(size, size));
    rect.setFillColor(sf::Color(160, 160, 160));
    rect.setPosition(new_x, new_y);
    symbol_sprite = sf::Sprite();
    symbol_sprite.setPosition(new_x, new_y);

}

void Tile::set_textures(sf::Texture *new_p0_texture, sf::Texture *new_p1_texture,
                        sf::Texture *new_empty_texture) {
    p0_texture = new_p0_texture;
    p1_texture = new_p1_texture;
    empty_texture = new_empty_texture;
}

void Tile::set_player(int player_id) {
    if (player_id == 0)
        symbol_sprite.setTexture(*p0_texture);
    else if (player_id == 1)
        symbol_sprite.setTexture(*p1_texture);
    else if (player_id == -1)
        symbol_sprite.setTexture(*empty_texture);
    else
        return;
    taken_player_id = player_id;
    adjust_size();
}

void Tile::adjust_size() {
    auto texture_size = symbol_sprite.getTexture()->getSize();
    symbol_sprite.setScale(size / texture_size.x, size / texture_size.y);
}