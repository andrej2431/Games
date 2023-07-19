#include "simon_says.h"

using namespace simon_says;

SimonSays::SimonSays(tgui::Group::Ptr new_menu, SessionData *new_session)
        : Game(new_menu, new_session) {
    canvas->setSize(menu->getSize().y * 0.8, "80%");
    canvas_pos = canvas->getAbsolutePosition();
    high_score = DatabaseManager::get_high_score(session->user.user_id, "simon_says");

    load_menu();
    load_tiles();
    new_game();
}

void SimonSays::new_game() {
    for (int y = 0; y < 2; y++)
        for (int x = 0; x < 2; x++)
            tiles[y][x].setFillColor(colors[x + 2 * y]);
    game_over_label->setVisible(false);
    pattern.clear();
    pattern.emplace_back(rand() % 2, rand() % 2);

    score = 0;
    activating_index = 0;
    deactivating_index = 0;
    tick = 0;
    update_scores();

    playing = true;
    showing_pattern = true;
}


void SimonSays::handle_event(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N) {
        new_game();
    } else if (event.type == sf::Event::MouseButtonPressed &&
               event.mouseButton.button == sf::Mouse::Button::Left) {
        float x = (float) event.mouseButton.x - canvas_pos.x;
        float y = (float) event.mouseButton.y - canvas_pos.y;
        for (int y_index = 0; y_index < 2; y_index++)
            for (int x_index = 0; x_index < 2; x_index++)
                if (tiles[y_index][x_index].getGlobalBounds().contains(x, y))
                    press_tile({x_index, y_index});
    }
}


void SimonSays::game_loop() {
    if (!playing)
        return;

    if (tick == 3 * speed)
        deactivate_tile();

    if (showing_pattern && tick == speed)
        activate_tile();

    tick++;
}


void SimonSays::draw() {
    if (!playing)
        return;

    canvas->clear(tgui::Color(100, 100, 100));

    for (auto &line: tiles)
        for (auto &rect: line)
            canvas->draw(rect);
    canvas->display();
}


void SimonSays::game_over(IntVector2d pos) {
    tiles[pos.y][pos.x].setFillColor(colors[pos.x + 2 * pos.y + 4]);
    canvas->draw(tiles[pos.y][pos.x]);
    canvas->display();
    game_over_label->setVisible(true);
    playing = false;
}

SimonSays::~SimonSays() {
    DatabaseManager::save_high_score(session->user.user_id, "simon_says", high_score);
}