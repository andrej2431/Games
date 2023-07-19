#include "entity.h"

using namespace snake;

Entity::Entity(const sf::Texture *texture, float new_size) {
    sprite = sf::Sprite();
    size = new_size;
    set_texture(texture);
}


IntVector2d Entity::get_position() {
    return position;
}


sf::Sprite &Entity::get_sprite() {
    return sprite;
}


void Entity::set_position(IntVector2d new_position) {
    position = new_position;
    sprite.setPosition((float) position.x * size + size / 2, (float) position.y * size + size / 2);
}

void Entity::set_rotation(float rotation) {
    sprite.setRotation(rotation);
}

void Entity::set_texture(const sf::Texture *new_texture) {
    sprite.setTexture(*new_texture);
    sprite.setOrigin((float) new_texture->getSize().x / 2, (float) new_texture->getSize().y / 2);
    update_scale();
}


void Entity::update_scale() {
    auto texture_size = sprite.getTexture()->getSize();
    sprite.setScale(size / (float) texture_size.x, size / (float) texture_size.y);

}



