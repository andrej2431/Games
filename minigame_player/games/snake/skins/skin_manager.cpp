#include "skin_manager.h"

using namespace snake;

SkinManager::SkinManager(State *new_state, tgui::Group::Ptr new_menu) {
    state = new_state;
    skin_menu = tgui::HorizontalLayout::create();
    skin_menu->setSize("100%", "20%");
    skin_menu->setPosition("1%", "83%");

    skin_selection_label = tgui::Label::create("Skins");
    skin_selection_label->setTextSize(50);
    skin_selection_label->setPosition("43%", "70%");

    new_menu->add(skin_selection_label);
    new_menu->add(skin_menu);
    current_index = 0;
    skins.push_back(new BaseSkin(state));
    skins.push_back(new ClassicSkin(state));
    skins.push_back(new MatrixSkin(state));
    load_menu();
    set_skin(0);

}

void SkinManager::key_pressed(sf::Keyboard::Key key_code) {
    switch (key_code) {
        case sf::Keyboard::Left:
            set_skin((current_index + 2) % (int) skins.size());
            break;
        case sf::Keyboard::Right:
            set_skin((current_index + 1) % (int) skins.size());
            break;
        default:
            skins[current_index]->key_pressed(key_code);
            break;

    }
}

void SkinManager::set_skin(int index) {
    if (state->skin_change_cd > 0)
        return;

    skin_selection[current_index]->setTextSize(30);
    skin_selection[index]->setTextSize(50);
    skins[current_index]->unload_skin();
    current_index = index;
    skins[index]->load_skin();
}

void SkinManager::load_menu() {

    for (auto &skin: skins) {
        auto skin_label = tgui::Label::create(skin->get_name());
        skin_label->setSize("30%", "100%");
        skin_label->setTextSize(30);
        skin_label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
        skin_selection.push_back(skin_label);
        skin_menu->add(skin_label);
    }

}