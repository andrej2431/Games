#include "classic.h"

using namespace snake;

ClassicSkin::ClassicSkin(State *new_state) : Skin(new_state) {
    load_textures(skin_name);
}


void ClassicSkin::eat_food(IntVector2d food_position) {
    state->free_tiles.erase(state->body.back().get_position());
    state->food_tiles.erase(food_position);
    (*state->score) += 2;
    if (state->ticks_per_tile > 3)
        state->ticks_per_tile -= std::min(state->ticks_per_tile - 3, 2);
    spawn_food();
}