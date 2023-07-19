#include "controllers/game_controller.h"

GameController::GameController(tgui::Group::Ptr new_menu, SessionData *new_session) {
    session = new_session;
    menu = new_menu;
    running_game = nullptr;
}

void GameController::mainloop() {
    if (is_game_running()) {
        running_game->game_loop();
        running_game->draw();
    }
}

void GameController::handle_input(sf::Event &event) {
    if (is_game_running()) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            raise_event(Event(Event::CLOSE_GAME));
        else
            running_game->handle_event(event);
    }

}

bool GameController::is_game_running() {
    if (running_game == nullptr) return false;
    else return true;
}


void GameController::start_game(int game_name) {
    switch (game_name) {
        case Game::NONE:
            running_game = nullptr;
            break;
        case Game::SNAKE:
            running_game = new snake::Snake(menu, session);
            break;
        case Game::SIMON_SAYS:
            running_game = new simon_says::SimonSays(menu, session);
            break;
        case Game::MATCH_PAIRS:
            running_game = new match_pairs::MatchPairs(menu, session);
            break;
        case Game::TIC_TAC_TOE:
            running_game = new tic_tac_toe::TicTacToe(menu, session);
            break;
        default:
            running_game = nullptr;
            break;
    }
}

void GameController::close_game() {
    delete running_game;
    running_game = nullptr;
}