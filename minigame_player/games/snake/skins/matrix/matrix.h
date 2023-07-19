#pragma once


#include "games/snake/skins/skin.h"

namespace snake {
    class MatrixSkin : public Skin {
    public:
        explicit MatrixSkin(State *new_state);

        void load_skin() override;

        void unload_skin() override;

        void spawn_food() override;

        void eat_food(IntVector2d) override;

        std::string get_name() override { return skin_name; };
        std::string skin_name = "matrix";
        int previous_speed = 20;
    private:
        int red_pill_value = 5;
        sf::Texture red_food_texture;
        IntVector2d red_position;
        bool red_pilled = false;
    };
}