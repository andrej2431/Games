#pragma once

#include "games/snake/skins/skin.h"

namespace snake {
    class BaseSkin : public Skin {
    public:
        explicit BaseSkin(State *new_state);

        void eat_food(IntVector2d) override;

        void load_skin() override;

        void unload_skin() override;

        std::string get_name() override { return skin_name; };
        std::string skin_name = "base";
    private:
        int previous_speed = 20;
        int base_speed = 12;
    };
}