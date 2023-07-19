#include "snake.h"

using namespace snake;

Snake::Snake(tgui::Group::Ptr new_menu, SessionData *new_session)
        : Game(new_menu, new_session) {
    int width = 32, height = 20;

    float canvas_height = height * menu->getSize().x / width;
    canvas->setSize("100%", canvas_height);
    tile_size = menu->getSize().x / (float) width;

    state = new State(tile_size, width, height, &score, &high_score);
    skin_manager = new SkinManager(state, menu);

    map_sprite.setTexture(state->map_texture);
    map_sprite.setTextureRect(sf::IntRect(0, 0,
                                          width * tile_size,
                                          height * tile_size));
    *state->high_score = DatabaseManager::get_high_score(session->user.user_id, "snake");
    load_menu();
    score_label->setPosition("50%", "95%");
    high_score_label->setPosition("0%", "95%");
    game_over_label->setPosition("15%", "20%");
    game_over_label->getRenderer()->setTextColor(tgui::Color::White);
    new_game();

}

void Snake::new_game() {
    score = 0;
    update_scores();
    game_over_label->setVisible(false);

    state->orientation = {1, 0};
    state->next_orientation = {1, 0};
    state->body.clear();
    state->food_tiles.clear();
    state->free_tiles.clear();

    for (int y = 0; y < state->arena_height; y++)
        for (int x = 0; x < state->arena_width; x++)
            state->free_tiles.emplace(x, y);
    skin_manager->get_skin()->spawn_snake();
    skin_manager->get_skin()->load_skin();
    skin_manager->get_skin()->spawn_food();
    state->ticks_per_tile = 12;
    state->current_ticks = 0;
    state->playing = true;
}

void Snake::game_loop() {
    if (state->do_game_over)
        game_over();

    if (!state->playing)
        return;

    skin_manager->get_skin()->game_loop();
    update_scores();
}


void Snake::draw() {
    if (!state->playing)
        return;

    canvas->clear(tgui::Color::Green);
    canvas->draw(map_sprite);

    for (auto &body_part: state->body)
        canvas->draw(body_part.get_sprite());

    for (auto food: state->food_tiles)
        canvas->draw(food.second.get_sprite());

    canvas->display();

}

void Snake::handle_event(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::N:
                new_game();
                break;
            default:
                skin_manager->key_pressed(event.key.code);
                break;
        }
    }
}

void Snake::game_over() {
    state->skin_change_cd = 0;
    skin_manager->get_skin()->unload_skin();
    float head_rotation = skin_manager->get_skin()->rotation_map[state->next_orientation];
    state->body.front().set_rotation(head_rotation);
    game_over_label->setVisible(true);
    state->do_game_over = false;
    state->playing = false;
}


Snake::~Snake() {
    delete skin_manager;
    delete state;
    DatabaseManager::save_high_score(session->user.user_id, "snake", high_score);
}