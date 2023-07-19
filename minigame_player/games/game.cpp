#include "game.h"
#include "events/event_stream.h"

Game::Game(tgui::Group::Ptr parent_menu, SessionData *new_session) :
        session(new_session) {
    menu = tgui::Group::create();
    canvas = tgui::CanvasSFML::create();
    canvas->setSize("100%", "80%");
    menu->add(canvas);
    parent_menu->add(menu);
}

void Game::load_menu() {
    score_label = tgui::Label::create("Score: 0");
    score_label->setSize("40%", "5%");
    score_label->setPosition("40%", menu->getSize().y * 0.85);
    score_label->setTextSize(30);
    score_label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
    menu->add(score_label);
    
    high_score_label = tgui::Label::create("HighScore: 0");
    high_score_label->setSize("40%", "10%");
    high_score_label->setPosition("0%", menu->getSize().y * 0.85);
    high_score_label->setTextSize(30);
    high_score_label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
    menu->add(high_score_label);

    game_over_label = tgui::Label::create("     Game Over!\nPress N for new game.");
    game_over_label->setPosition("5%", "20%");
    game_over_label->getRenderer()->setTextColor(tgui::Color::Black);
    game_over_label->setTextSize(60);
    game_over_label->setVisible(false);
    menu->add(game_over_label);
    raise_event(Event(Event::UPDATE_LEADERBOARD, 0, get_name()));
    high_score = DatabaseManager::get_high_score(session->user.user_id, get_name());

}


void Game::update_scores() {

    if (score > high_score) {
        high_score = score;
        DatabaseManager::save_high_score(session->user.user_id, get_name(), high_score);
        raise_event(Event(Event::UPDATE_LEADERBOARD, 0, get_name()));
    }

    score_label->setText("Score: " + std::to_string(score));
    high_score_label->setText("HighScore: " + std::to_string(high_score));

}

Game::~Game() {
    menu->getParent()->remove(menu);
}
