#include "feats_submenu.h"

FeatsSubmenu::FeatsSubmenu() : Menu() {
    menu->setSize("32%", "90%");
    menu->setPosition("51%", "5%");
    auto leaderboards_label = tgui::Label::create("Leaderboard");
    leaderboards_label->setSize("100%", "5%");
    leaderboards_label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
    leaderboards_label->setTextSize(35);

    game_name_label = tgui::Label::create("");
    game_name_label->setSize("100%", "5%");
    game_name_label->setPosition("", "10%");
    game_name_label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
    game_name_label->setTextSize(30);

    score_list = tgui::Group::create();
    score_list->setSize("100%", "70%");
    score_list->setPosition("0%", "20%");

    menu->add(game_name_label);
    menu->add(leaderboards_label);
    menu->add(score_list);
}

void FeatsSubmenu::update_leaderboard(const std::string &game_name) {
    game_name_label->setVisible(true);
    game_name_label->setText(game_name);
    LeaderboardData leaderboard = DatabaseManager::get_leaderboard(game_name);
    score_list->removeAllWidgets();
    double score_height = score_list->getSize().y * 0.0625;
    int i = 0;
    for (auto &item: leaderboard.scores) {
        auto score_label = tgui::Label::create(item.first
                                               + "   " + std::to_string(item.second));

        score_label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
        score_label->setSize("100%", score_height);
        score_label->setPosition("0%", i * score_height);
        score_label->setTextSize(20);
        score_list->add(score_label);
        i++;
    }
}

void FeatsSubmenu::hide_leaderboard() {

    game_name_label->setVisible(false);
    score_list->removeAllWidgets();
}