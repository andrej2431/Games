#include "main_submenu.h"

void MainSubmenu::load_library() {

    auto library_label = tgui::Label::create("Library");
    library_label->setSize("100%", "5%");
    library_label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
    library_label->setTextSize(35);

    library_button_textures["Snake"] = sf::Texture();
    library_button_textures["Snake"].loadFromFile("../games/snake/snake.png");

    library_button_textures["Simon_Says"] = sf::Texture();
    library_button_textures["Simon_Says"].loadFromFile("../games/simon_says/simon_says.png");

    library_button_textures["Match_Pairs"] = sf::Texture();
    library_button_textures["Match_Pairs"].loadFromFile("../games/match_pairs/match_pairs.png");

    library_button_textures["Tic_Tac_Toe"] = sf::Texture();
    library_button_textures["Tic_Tac_Toe"].loadFromFile("../games/tic_tac_toe/tic_tac_toe.png");


    auto snake_button = tgui::Button::create("");
    snake_button->onPress([]() { raise_event(Event(Event::START_GAME, Game::SNAKE)); });
    snake_button->setSize("10%", "10%");
    snake_button->setPosition("10%", "10%");
    snake_button->getRenderer()->setTexture(library_button_textures["Snake"]);

    auto simon_says_button = tgui::Button::create("");
    simon_says_button->onPress([]() { raise_event(Event(Event::START_GAME, Game::SIMON_SAYS)); });
    simon_says_button->setSize("10%", "10%");
    simon_says_button->setPosition("25%", "10%");
    simon_says_button->getRenderer()->setTexture(library_button_textures["Simon_Says"]);

    auto match_pairs_button = tgui::Button::create("");
    match_pairs_button->onPress([]() { raise_event(Event(Event::START_GAME, Game::MATCH_PAIRS)); });
    match_pairs_button->setSize("10%", "10%");
    match_pairs_button->setPosition("40%", "10%");
    match_pairs_button->getRenderer()->setTexture(library_button_textures["Match_Pairs"]);

    auto tic_tac_toe_button = tgui::Button::create("");
    tic_tac_toe_button->onPress([]() { raise_event(Event(Event::START_GAME, Game::TIC_TAC_TOE)); });
    tic_tac_toe_button->setSize("10%", "10%");
    tic_tac_toe_button->setPosition("55%", "10%");
    tic_tac_toe_button->getRenderer()->setTexture(library_button_textures["Tic_Tac_Toe"]);


    library->add(library_label);
    library->add(snake_button);
    library->add(simon_says_button);
    library->add(match_pairs_button);
    library->add(tic_tac_toe_button);

}