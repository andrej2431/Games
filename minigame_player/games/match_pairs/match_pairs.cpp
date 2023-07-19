#include "match_pairs.h"

using namespace match_pairs;

MatchPairs::MatchPairs(tgui::Group::Ptr new_menu, SessionData *new_session)
        : Game(new_menu, new_session) {
    canvas->setSize(menu->getSize().y * 0.8, "80%");
    canvas_size = canvas->getSize().y;
    canvas_pos = canvas->getAbsolutePosition();
    high_score = DatabaseManager::get_high_score(session->user.user_id, "match_pairs");

    load_menu();
    load_moves_label();
    load_tiles();
    new_game();
}

void MatchPairs::handle_event(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N) {
        new_game();
    } else if (event.type == sf::Event::MouseButtonPressed &&
               event.mouseButton.button == sf::Mouse::Button::Left) {
        if (!playing)
            return;

        float x = (float) event.mouseButton.x - canvas_pos.x;
        float y = (float) event.mouseButton.y - canvas_pos.y;
        if (x >= 0 && y >= 0 && x <= canvas_size && y <= canvas_size) {
            for (Tile &tile: tiles)
                if (tile.position_in_rect({x, y}))
                    press_tile(tile);
        }
    }
}

void MatchPairs::game_loop() {
    if (!playing)
        return;

    if (tick == 40) {
        turned_over->turn_over();
        turned_over_2->turn_over();
        turned_over = nullptr;
        turned_over_2 = nullptr;
        moves--;
        moves_label->setText("Tries Left: " + std::to_string(moves));
        if (moves == 0)
            game_over();
    }

    tick++;
}

void MatchPairs::press_tile(Tile &tile) {
    if (!tile.is_facing_down() || tick <= 40)
        return;
    tile.turn_over();
    if (turned_over == nullptr)
        turned_over = &tile;
    else {
        turned_over_2 = &tile;
        if (turned_over->get_color() == turned_over_2->get_color())
            increase_score();
        else
            tick = 0;
    }

}


void MatchPairs::draw() {
    if (!playing)
        return;

    canvas->clear(tgui::Color(120, 120, 120));

    for (Tile &tile: tiles)
        canvas->draw(tile.get_rect());
    canvas->display();

}

void MatchPairs::increase_score() {
    turned_over = nullptr;
    turned_over_2 = nullptr;
    n_of_turned += 2;
    score++;
    update_scores();

    if (n_of_turned == 36) {
        n_of_turned = 0;
        for (Tile &tile: tiles)
            tile.turn_over();
        shuffle_tiles();
        if (score < 18 * 5)
            moves += 50 - ((int) score / 18) * 10;
    }
    moves_label->setText("Tries Left: " + std::to_string(moves));

}

void MatchPairs::game_over() {
    game_over_label->setVisible(true);
    playing = false;
}