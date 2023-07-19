#include "main_controller.h"

MainController::MainController(sf::VideoMode window_video_mode, sf::Uint32 window_style) {

    video_mode = window_video_mode;
    window = new sf::RenderWindow(video_mode, "Minihry", window_style);
    int fps = 60;
    window->setFramerateLimit(fps);
    session = new SessionData(video_mode.width, video_mode.height, fps);

    user_controller = new UserController(session);
    menu_controller = new MenuController(window, session);

    menu_controller->switch_to_menu(Menu::LOGIN);

    mainloop();
}

MainController::~MainController() {

    delete menu_controller;
    delete window;
    delete session;
}

void MainController::mainloop() {
    while (window->isOpen()) {
        manage_input();
        manage_events();
        window->clear(sf::Color(100, 100, 150));

        menu_controller->mainloop();

        window->display();
    }
}

void MainController::manage_input() {
    sf::Event sf_event;
    while (window->pollEvent(sf_event)) {
        menu_controller->handle_input(sf_event);

        if (sf_event.type == sf::Event::Closed)
            window->close();
    }

}

void MainController::manage_events() {

    Event event = EventStream::getInstance().get_event();
    while (event.type != Event::NONE) {
        handle_event(event);
        event = EventStream::getInstance().get_event();
    }
}
