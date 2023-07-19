#pragma once


#include "games/snake/skins/skin.h"

namespace snake {
    class ClassicSkin : public Skin {
    public:
        explicit ClassicSkin(State *new_state);

        void eat_food(IntVector2d) override;

        std::string get_name() override { return skin_name; };

        std::string skin_name = "classic";

    };
}