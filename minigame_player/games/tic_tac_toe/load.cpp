#include "tic_tac_toe.h"

using namespace tic_tac_toe;

void TicTacToe::load_labels() {
    game_over_label->setText("           You Lost!\nPress N for new game.");

    victory_label = tgui::Label::create("         You Won!\nPress N for new game.");
    victory_label->setPosition("5%", "20%");
    victory_label->getRenderer()->setTextColor(tgui::Color(255, 215, 0));
    victory_label->setTextSize(60);
    victory_label->setVisible(false);
    menu->add(victory_label);

    draw_label = tgui::Label::create("             Draw!\nPress N for new game.");
    draw_label->setPosition("5%", "20%");
    draw_label->getRenderer()->setTextColor(tgui::Color::White);
    draw_label->setTextSize(60);
    draw_label->setVisible(false);
    menu->add(draw_label);

    game_over_label->getRenderer()->setTextColor(tgui::Color::White);
}

void TicTacToe::load_tiles() {
    double padding = canvas_size * 0.025;
    for (int y = 0; y < 3; y++) {
        tiles.emplace_back(std::vector<Tile>());
        for (int x = 0; x < 3; x++) {
            tiles[y].emplace_back(padding + x * 0.325 * canvas_size,
                                  padding + y * 0.325 * canvas_size,
                                  canvas_size * 0.3);
            tiles[y][x].set_textures(&p0_texture, &p1_texture, &empty_texture);
        }
    }

}


TicTacToe::~TicTacToe() {
    DatabaseManager::save_high_score(session->user.user_id, "tic_tac_toe", high_score);
}

void TicTacToe::load_game_textures() {
    load_texture("games/tic_tac_toe/resources/o.png", p0_texture);
    load_texture("games/tic_tac_toe/resources/x.png", p1_texture);
    load_texture("games/tic_tac_toe/resources/empty.png", empty_texture);
}