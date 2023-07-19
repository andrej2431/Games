#include "main_controller.h"


void MainController::handle_event(Event &event) {
    switch (event.type) {
        case Event::WARNING:
            menu_controller->raise_warning(event.value);
            break;
        case Event::LOGIN:
            user_controller->user_login(menu_controller->get_login_credentials());
            if (session->user.user_id != 0)
                menu_controller->switch_to_menu(Menu::MAIN);
            break;

        case Event::REGISTER:
            user_controller->user_register(menu_controller->get_register_credentials());
            if (session->user.user_id != 0)
                menu_controller->switch_to_menu(Menu::MAIN);
            break;

        case Event::GUEST_JOIN:
            user_controller->join_as_guest();
            menu_controller->switch_to_menu(Menu::MAIN);
            break;

        case Event::LOGOUT:
            user_controller->log_out();
            menu_controller->switch_to_menu(Menu::LOGIN);
            break;

        case Event::SHOW_MENU:
            menu_controller->switch_to_menu(event.value);
            break;

        case Event::START_GAME:
            menu_controller->start_game(event.value);
            break;
        case Event::CLOSE_GAME:
            menu_controller->close_game();
            break;
        case Event::UPDATE_LEADERBOARD:
            menu_controller->update_leaderboard(event.message);
            break;
    }
}

