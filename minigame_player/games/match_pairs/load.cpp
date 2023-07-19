
#include "match_pairs.h"

using namespace match_pairs;

void MatchPairs::load_moves_label() {
    moves_label = tgui::Label::create("Tries left: " + std::to_string(moves));
    moves_label->setSize("30%", "5%");
    moves_label->setPosition("30%", menu->getSize().y * 0.9);
    moves_label->setTextSize(30);
    menu->add(moves_label);
}

void MatchPairs::load_tiles() {
    padding = canvas->getSize().y / 97;
    tile_size = padding * 15;
    for (auto color: colors) {
        tiles.emplace_back(color, tile_size);
        tiles.emplace_back(color, tile_size);
    }
}

void MatchPairs::shuffle_tiles() {
    std::vector<int> indices(36);
    std::iota(indices.begin(), indices.end(), 0);
    auto rd = std::random_device{};
    auto rng = std::default_random_engine{rd()};
    std::shuffle(indices.begin(), indices.end(), rng);
    int i = 0;
    for (int y = 0; y < 6; y++)
        for (int x = 0; x < 6; x++) {
            float x_pos = x * (tile_size + padding) + padding,
                    y_pos = y * (tile_size + padding) + padding;
            tiles[indices[i]].get_rect().setPosition(x_pos, y_pos);
            i++;
        }
}

void MatchPairs::new_game() {
    game_over_label->setVisible(false);
    for (Tile &tile: tiles)
        if (!tile.is_facing_down())
            tile.turn_over();
    score = 0;
    moves = 50;
    n_of_turned = 0;
    tick = 41;
    update_scores();
    moves_label->setText("Tries Left: " + std::to_string(moves));
    shuffle_tiles();
    turned_over = nullptr;
    playing = true;

}

MatchPairs::~MatchPairs() {
    DatabaseManager::save_high_score(session->user.user_id, "match_pairs", high_score);
    menu->remove(moves_label);
}