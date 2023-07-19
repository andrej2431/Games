#include "menu.h"

std::string Menu::get_editbox_value(const std::string &editbox_name) {
    return (std::string) menu->get<tgui::EditBox>(editbox_name)->getText();

}
