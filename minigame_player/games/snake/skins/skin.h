#pragma once

#include "games/snake/helper/state.h"

namespace snake {
    class Skin {
    public:
        explicit Skin(State *);

        virtual void spawn_snake();

        virtual void spawn_food();

        virtual void eat_food(IntVector2d);

        virtual void game_loop();

        virtual void key_pressed(sf::Keyboard::Key);

        virtual void move_snake();

        virtual void load_skin();

        virtual void unload_skin() {};

        virtual std::string get_name() { return "default name"; };

        sf::Texture head_texture;
        sf::Texture body_texture;
        sf::Texture body_turn_texture;
        sf::Texture map_texture;
        sf::Texture food_texture;

        std::map<IntVector2d, float> rotation_map = {
                {{-1, 0},  270},
                {{1,  0},  90},
                {{0,  -1}, 0},
                {{0,  1},  180},

                {{-1, -1}, 0},
                {{-1, 1},  270},
                {{1,  -1}, 90},
                {{1,  1},  180}};

    protected:
        void load_textures(const std::string &);

        inline void take_up_head_tile() { state->free_tiles.erase(state->body.front().get_position()); };

        State *state;


    };
}
