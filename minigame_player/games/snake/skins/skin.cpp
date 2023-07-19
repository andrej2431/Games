#include "skin.h"

using namespace snake;

Skin::Skin(State *new_state) {
    state = new_state;
}

void Skin::game_loop() {

    if (state->current_ticks % state->ticks_per_tile == 0) {
        IntVector2d new_position = state->body.front().get_position() + state->next_orientation;
        state->free_tiles.insert(state->body.back().get_position());


        bool tile_free = state->free_tiles.contains(new_position),
                tile_taken_by_food = state->food_tiles.contains(new_position);

        if (tile_free)
            state->body.pop_back();

        if (!tile_free && tile_taken_by_food)
            eat_food(new_position);

        if (!tile_free && !tile_taken_by_food)
            state->do_game_over = true;
        else
            move_snake();
        take_up_head_tile();
        if (state->skin_change_cd > 0)
            state->skin_change_cd--;


    }

    state->current_ticks++;
}

void Skin::eat_food(IntVector2d food_position) {
    state->free_tiles.erase(state->body.back().get_position());
    state->food_tiles.erase(food_position);
    (*state->score)++;
    spawn_food();
}

void Skin::move_snake() {
    auto &body = state->body;
    IntVector2d new_position = state->body.front().get_position() + state->next_orientation;
    IntVector2d turn_vector = state->orientation - state->next_orientation;

    if (turn_vector.x == 0 && turn_vector.y == 0) {
        body.front().set_texture(&state->body_texture);
    } else {
        body.front().set_texture(&state->body_turn_texture);
        body.front().set_rotation(rotation_map[turn_vector]);
    }

    body.emplace_front(&state->head_texture, state->tile_size);
    body.front().set_position(new_position);
    body.front().set_rotation(rotation_map[state->next_orientation]);
    state->orientation = state->next_orientation;
}

void Skin::spawn_food() {
    int rnd = rand() % state->free_tiles.size();
    auto it = state->free_tiles.begin();
    std::advance(it, rnd);

    state->food_tiles[*it] = Entity(&state->food_texture, state->tile_size);
    state->food_tiles[*it].set_position(*it);
    state->free_tiles.erase(*it);
}

void Skin::spawn_snake() {
    state->body.emplace_front(&state->head_texture, state->tile_size);
    state->body.front().set_position({state->arena_width / 2, state->arena_height / 2});
    state->body.front().set_rotation(270);
    take_up_head_tile();
    move_snake();
    take_up_head_tile();
    move_snake();
    take_up_head_tile();
    move_snake();
    take_up_head_tile();

}

void Skin::key_pressed(sf::Keyboard::Key key_code) {
    switch (key_code) {
        case sf::Keyboard::A:
            if (state->orientation.x != 1)
                state->next_orientation = {-1, 0};
            break;
        case sf::Keyboard::D:
            if (state->orientation.x != -1)
                state->next_orientation = {1, 0};
            break;
        case sf::Keyboard::W:
            if (state->orientation.y != 1)
                state->next_orientation = {0, -1};
            break;
        case sf::Keyboard::S:
            if (state->orientation.y != -1)
                state->next_orientation = {0, 1};
            break;
        default:
            break;
    }
}

void Skin::load_skin() {
    state->head_texture = head_texture;
    state->body_texture = body_texture;
    state->body_turn_texture = body_turn_texture;
    state->food_texture = food_texture;
    state->map_texture = map_texture;

}

void Skin::load_textures(const std::string &skin_name) {
    std::string resource_path = "games/snake/skins/" + skin_name + "/resources/";
    load_texture(resource_path + "map.png", map_texture);
    load_texture(resource_path + "head.png", head_texture);
    load_texture(resource_path + "body.png", body_texture);
    load_texture(resource_path + "body_turn.png", body_turn_texture);
    load_texture(resource_path + "food.png", food_texture);
}