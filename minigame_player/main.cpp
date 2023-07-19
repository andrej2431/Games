#include "main.h"

int main() {
    std::srand(std::time(nullptr));
    auto main_controller = MainController(sf::VideoMode(1920, 1080), sf::Style::Fullscreen);

    return 0;
}
