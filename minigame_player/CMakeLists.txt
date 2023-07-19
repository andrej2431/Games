cmake_minimum_required(VERSION 3.20)
project(Minigames)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(Minigames main.cpp
        events/warning.cpp events/event_stream.cpp

        database/database_manager.cpp database/data_conversion.cpp
        database/database_helper_functions.cpp

        games/game.cpp

        games/snake/helper/entity.cpp
        games/snake/skins/skin.cpp
        games/snake/skins/base/base.cpp
        games/snake/skins/classic/classic.cpp
        games/snake/skins/matrix/matrix.cpp
        games/snake/skins/skin_manager.cpp
        games/snake/snake.cpp

        games/simon_says/simon_says.cpp
        games/simon_says/tile_management.cpp

        games/match_pairs/match_pairs.cpp
        games/match_pairs/load.cpp
        games/match_pairs/tile.cpp

        games/tic_tac_toe/tic_tac_toe.cpp
        games/tic_tac_toe/load.cpp
        games/tic_tac_toe/tile.cpp

        menu/menu.cpp
        menu/notification_menu.cpp
        menu/login_menu.cpp
        menu/register_menu.cpp
        menu/submenu/user_submenu/user_submenu.cpp
        menu/submenu/feats_submenu/feats_submenu.cpp
        menu/submenu/main_submenu/main_submenu.cpp
        menu/submenu/main_submenu/main_submenu.h
        menu/submenu/user_submenu/submenu_loads.cpp
        menu/submenu/main_submenu/submenu_loads.cpp
        menu/main_menu.cpp

        controllers/user_controller.cpp
        controllers/game_controller.cpp
        controllers/menu_controller.cpp
        controllers/main_controller.cpp
        controllers/main_controller_events.cpp

        )


target_link_libraries(Minigames jsoncpp sfml-graphics sfml-window sfml-system tgui)
