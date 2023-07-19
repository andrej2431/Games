#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "dataclasses/dataclasses.h"
#include "games/game.h"
#include "events/event_stream.h"

class Menu {
public:
    enum {
        NONE, LOGIN, REGISTER, MAIN, NOTIFICATION
    };

    Menu() {
        menu = tgui::Group::create();
    }

    tgui::Group::Ptr get() { return menu; };

    virtual void hide() { menu->setVisible(false); };

    virtual void show() { menu->setVisible(true); };

    std::string get_editbox_value(const std::string &);

    virtual std::string get_name() = 0;

protected:
    tgui::Group::Ptr menu;
};

