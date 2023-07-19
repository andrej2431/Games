#pragma once

#include "games/game.h"
#include "entity.h"

namespace snake {
    using GameVectors::IntVector2d;

    struct State {
        explicit State(float ts, int aw, int ah, int *s, int *hs) :
                tile_size(ts), arena_width(aw), arena_height(ah),
                score(s), high_score(hs) {};
        float tile_size;
        int arena_width, arena_height;
        int ticks_per_tile = 20;
        int *score, *high_score;

        bool do_game_over = false;
        bool playing = false;
        int current_ticks = 0;
        int skin_change_cd = 0;

        IntVector2d next_orientation = {1, 0}, orientation = {1, 0};
        std::deque<Entity> body;

        std::set<IntVector2d> free_tiles;
        std::map<IntVector2d, Entity> food_tiles;
        sf::Texture head_texture;
        sf::Texture body_texture;
        sf::Texture body_turn_texture;
        sf::Texture map_texture;
        sf::Texture food_texture;

    };

}