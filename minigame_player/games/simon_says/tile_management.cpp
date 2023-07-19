#include "simon_says.h"

using namespace simon_says;

void SimonSays::load_tiles() {
    padding = canvas->getSize().y / 23;
    tile_size = padding * 10;

    for (int y = 0; y < 2; y++) {
        tiles.emplace_back(std::vector<sf::RectangleShape>());
        for (int x = 0; x < 2; x++) {
            float x_pos = padding + (padding + tile_size) * (float) x,
                    y_pos = padding + (padding + tile_size) * (float) y;
            tiles[y].emplace_back(sf::Vector2f(tile_size, tile_size));
            tiles[y][x].setPosition(x_pos, y_pos);

        }
    }
}

void SimonSays::press_tile(IntVector2d tile) {
    if (!playing || tile.x < 0)
        return;

    if (showing_pattern) {
        game_over(tile);
        return;
    }

    if (activating_index == deactivating_index) {
        tick = 2 * speed;
        if (pattern[activating_index] == tile)
            activate_tile();
        else
            game_over(tile);
    }
}

void SimonSays::activate_tile() {
    IntVector2d pos = pattern[activating_index];
    tiles[pos.y][pos.x].setFillColor(colors[pos.x + 2 * pos.y + 4]);
    activating_index++;
}

void SimonSays::deactivate_tile() {
    if (deactivating_index + 1 == activating_index) {
        IntVector2d pos = pattern[deactivating_index];
        tiles[pos.y][pos.x].setFillColor(colors[pos.x + 2 * pos.y]);
        tick = 0;
        deactivating_index++;

        if (activating_index >= pattern.size()) {
            if (!showing_pattern) {
                pattern.emplace_back(rand() % 2, rand() % 2);
                score++;
                update_scores();

            }
            showing_pattern = !showing_pattern;
            activating_index = 0;
            deactivating_index = 0;
        }
    }


}