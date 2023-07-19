#pragma once

#include "menu/menu.h"

class FeatsSubmenu : public Menu {
public:
    FeatsSubmenu();

    void update_leaderboard(const std::string &);

    void hide_leaderboard();

    std::string get_name() override { return "leaderboard_menu"; };
private:
    tgui::Label::Ptr game_name_label;
    tgui::Group::Ptr score_list;
};