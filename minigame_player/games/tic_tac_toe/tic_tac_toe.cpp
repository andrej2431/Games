#include "tic_tac_toe.h"
#include <utility>

using namespace tic_tac_toe;
using GameVectors::IntVector2d;

TicTacToe::TicTacToe(tgui::Group::Ptr new_menu, SessionData *new_session)
        : Game(new_menu, new_session) {
    canvas->setSize(menu->getSize().y * 0.8, "80%");
    canvas_size = canvas->getSize().y;
    canvas_pos = canvas->getAbsolutePosition();
    high_score = DatabaseManager::get_high_score(session->user.user_id, "tic_tac_toe");
    load_menu();
    load_labels();
    load_game_textures();
    load_tiles();
    new_game();
}

void TicTacToe::handle_event(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N) {
        new_game();
    } else if (event.type == sf::Event::MouseButtonPressed &&
               event.mouseButton.button == sf::Mouse::Button::Left) {
        float x_pos = (float) event.mouseButton.x - canvas_pos.x;
        float y_pos = (float) event.mouseButton.y - canvas_pos.y;
        for (int y = 0; y < 3; y++)
            for (int x = 0; x < 3; x++)
                if (tiles[y][x].get_rect().getGlobalBounds().contains(x_pos, y_pos))
                    tile_clicked(x, y);
    }
}

void TicTacToe::tile_clicked(int x, int y) {
    if (!playing || tiles[y][x].get_player() != -1)
        return;
    tiles[y][x].set_player(0);
    draw();
    if (game_result() != -1)
        game_over();
    else {
        opponent_respond();
        draw();
        if (game_result() != -1)
            game_over();
    }
}

void TicTacToe::game_loop() {
}

void TicTacToe::opponent_respond() {
    std::vector<IntVector2d> free_tiles, valid_tiles, result_tile;
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            if (tiles[y][x].get_player() == -1)
                free_tiles.emplace_back(x, y);

    for (auto &pos: free_tiles) {
        tiles[pos.y][pos.x].set_player(1);
        if (game_result() == 1)
            return;
        tiles[pos.y][pos.x].set_player(-1);
    }
    for (auto &pos: free_tiles) {
        tiles[pos.y][pos.x].set_player(0);
        if (game_result() == 0) {
            tiles[pos.y][pos.x].set_player(1);
            return;
        }
        valid_tiles.emplace_back(pos.x, pos.y);
        tiles[pos.y][pos.x].set_player(-1);
    }
    std::sample(valid_tiles.begin(), valid_tiles.end(),
                std::back_inserter(result_tile), 1,
                std::mt19937{std::random_device{}()});

    tiles[result_tile[0].y][result_tile[0].x].set_player(1);
}


int TicTacToe::game_result() {
    for (int i = 0; i < 3; i++) {
        if (tiles[i][0].get_player() != -1 &&
            tiles[i][0] == tiles[i][1] && tiles[i][1] == tiles[i][2])
            return tiles[i][0].get_player();

        if (tiles[0][i].get_player() != -1 &&
            tiles[0][i] == tiles[1][i] && tiles[1][i] == tiles[2][i])
            return tiles[0][i].get_player();
    }

    if (tiles[1][1].get_player() != -1)
        if ((tiles[0][0] == tiles[1][1] && tiles[1][1] == tiles[2][2]) ||
            (tiles[0][2] == tiles[1][1] && tiles[2][0] == tiles[1][1]))
            return tiles[1][1].get_player();

    for (auto &line: tiles)
        for (auto &tile: line)
            if (tile.get_player() == -1)
                return -1;
    return 2;

}

void TicTacToe::draw() {
    if (!playing)
        return;

    canvas->clear(tgui::Color(100, 100, 100));

    for (auto &line: tiles)
        for (auto &tile: line) {
            canvas->draw(tile.get_rect());
            if (tile.get_player() != -1)
                canvas->draw(tile.get_sprite());

        }

    canvas->display();
}

void TicTacToe::new_game() {
    game_over_label->setVisible(false);
    draw_label->setVisible(false);
    victory_label->setVisible(false);
    update_scores();
    for (auto &line: tiles)
        for (auto &tile: line)
            tile.set_player(-1);
    playing = true;
}

void TicTacToe::game_over() {
    int victorious_player = game_result();
    playing = false;

    if (victorious_player == 0) {
        score++;
        victory_label->setVisible(true);
    } else if (victorious_player == 1) {
        score = 0;
        game_over_label->setVisible(true);
    } else
        draw_label->setVisible(true);

    update_scores();
}


