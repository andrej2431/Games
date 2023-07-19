#include "matrix.h"

using namespace snake;

MatrixSkin::MatrixSkin(State *new_state) : Skin(new_state) {
    load_textures(skin_name);
    load_texture("games/snake/skins/matrix/resources/food2.png", red_food_texture);

}

void MatrixSkin::load_skin() {
    Skin::load_skin();
    red_pilled = false;
    previous_speed = state->ticks_per_tile;
    state->ticks_per_tile = 15;
    int rnd = rand() % state->free_tiles.size();
    auto it = state->free_tiles.begin();
    std::advance(it, rnd);

    state->food_tiles[*it] = Entity(&red_food_texture, state->tile_size);
    state->food_tiles[*it].set_position(*it);
    state->free_tiles.erase(*it);
    red_position = {it->x, it->y};
}

void MatrixSkin::spawn_food() {
    int rnd = rand() % state->free_tiles.size();
    auto it = state->free_tiles.begin();
    std::advance(it, rnd);

    if (!red_pilled)
        state->food_tiles[*it] = Entity(&state->food_texture, state->tile_size);
    else
        state->food_tiles[*it] = Entity(&red_food_texture, state->tile_size);

    state->food_tiles[*it].set_position(*it);
    state->free_tiles.erase(*it);
}

void MatrixSkin::eat_food(IntVector2d food_position) {
    state->free_tiles.erase(state->body.back().get_position());
    state->food_tiles.erase(food_position);
    if (!red_pilled && food_position == red_position) {
        red_pilled = true;
        state->ticks_per_tile = 2;
        state->skin_change_cd = INT_MAX;
        state->free_tiles.insert(state->food_tiles.begin()->first);
        state->food_tiles.clear();
    }
    if (red_pilled)
        *state->score += red_pill_value;
    else
        (*state->score)++;
    spawn_food();
}


void MatrixSkin::unload_skin() {
    state->ticks_per_tile = previous_speed;
    state->free_tiles.insert(red_position);
    state->food_tiles.erase(red_position);
};