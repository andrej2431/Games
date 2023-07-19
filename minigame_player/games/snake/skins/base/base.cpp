#include "base.h"

using namespace snake;

BaseSkin::BaseSkin(State *new_state) : Skin(new_state) {
    load_textures(skin_name);
}

void BaseSkin::load_skin() {
    Skin::load_skin();
    previous_speed = state->ticks_per_tile;
    state->ticks_per_tile = base_speed;
}

void BaseSkin::eat_food(IntVector2d food_position) {
    Skin::eat_food(food_position);
    if (previous_speed < base_speed)
        previous_speed++;
}

void BaseSkin::unload_skin() {
    state->ticks_per_tile = previous_speed;
}