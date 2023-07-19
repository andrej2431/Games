#pragma once

#include "games/game.h"

namespace snake {
    using namespace GameVectors;

    class Entity {
    public:
        Entity() : size(0) {};

        Entity(const sf::Texture *, float);

        IntVector2d get_position();

        sf::Sprite &get_sprite();


        void set_position(IntVector2d);

        void set_rotation(float);

        void set_texture(const sf::Texture *);

    private:
        void update_scale();

        float size;
        IntVector2d position;
        sf::Sprite sprite;
    };

}