#include "menu_controller.h"

MenuController::MenuController(sf::RenderWindow *window, SessionData *new_session) {
    gui = new tgui::Gui(*window);

    session = new_session;
    login_menu = new LoginMenu();
    register_menu = new RegisterMenu();
    main_menu = new MainMenu();
    notification_menu = new NotificationMenu();
    main_menu->session = session;

    gui->add(login_menu->get(), login_menu->get_name());
    gui->add(register_menu->get(), register_menu->get_name());
    gui->add(main_menu->get(), main_menu->get_name());
    gui->add(notification_menu->get(), notification_menu->get_name());

    game_controller = new GameController(main_menu->main_submenu->get(), session);
}

Menu *MenuController::get_menu(int menu_number) {
    if (menu_number == Menu::NONE) return nullptr;
    if (menu_number == Menu::LOGIN) return login_menu;
    if (menu_number == Menu::REGISTER) return register_menu;
    if (menu_number == Menu::MAIN) return main_menu;
    throw std::invalid_argument("Invalid menu_number in UserController::get_menu() !!!");
}

void MenuController::switch_to_menu(int menu_number) {
    if (game_controller->is_game_running())
        game_controller->close_game();
    main_menu->feats_submenu->hide_leaderboard();
    Menu *previous_menu = get_menu(session->menu);
    if (previous_menu != nullptr)
        previous_menu->hide();
    get_menu(menu_number)->show();
    session->menu = menu_number;
    notification_menu->destroy_all_warnings();

}

void MenuController::mainloop() {
    try {
        game_controller->mainloop();
    } catch (std::exception &exc) {
        raise_warning(Warning::GAME_CRASHED);
        game_controller->close_game();
        main_menu->main_submenu->show_default();
    }

    gui->draw();
}

void MenuController::handle_input(sf::Event &input) {
    gui->handleEvent(input);
    game_controller->handle_input(input);
}

LoginCredentials MenuController::get_login_credentials() {
    LoginCredentials credentials;
    credentials.username = login_menu->get_editbox_value("username_editbox");
    credentials.password = login_menu->get_editbox_value("password_editbox");
    return credentials;
}

RegisterCredentials MenuController::get_register_credentials() {
    RegisterCredentials credentials;
    credentials.username = register_menu->get_editbox_value("username_editbox");
    credentials.password1 = register_menu->get_editbox_value("password1_editbox");
    credentials.password2 = register_menu->get_editbox_value("password2_editbox");
    return credentials;
}

void MenuController::start_game(int game_number) {
    main_menu->main_submenu->show_game();
    try {
        game_controller->start_game(game_number);
    } catch (std::exception &exc) {
        raise_warning(Warning::GAME_CRASHED);
        game_controller->close_game();
        main_menu->main_submenu->show_default();
    }
}

void MenuController::raise_warning(int warning_type) {
    std::string message = Warning::get_message(warning_type);
    notification_menu->display_warning(message);
}

void MenuController::close_game() {
    game_controller->close_game();
    main_menu->feats_submenu->hide_leaderboard();
    main_menu->main_submenu->show_default();
}

void MenuController::update_leaderboard(const std::string &game_name) {
    main_menu->feats_submenu->update_leaderboard(game_name);
}