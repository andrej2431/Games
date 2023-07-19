#pragma once

#include "skin.h"
#include "base/base.h"
#include "classic/classic.h"
#include "matrix/matrix.h"

namespace snake {
    class SkinManager {
    public:
        SkinManager(State *, tgui::Group::Ptr);

        void key_pressed(sf::Keyboard::Key);

        void set_skin(int index);

        Skin *get_skin() { return skins[current_index]; };

    private:
        void load_menu();

        tgui::Label::Ptr skin_selection_label;
        tgui::HorizontalLayout::Ptr skin_menu;
        State *state;
        int current_index;
        std::vector<tgui::Label::Ptr> skin_selection;
        std::vector<Skin *> skins;

    };

}