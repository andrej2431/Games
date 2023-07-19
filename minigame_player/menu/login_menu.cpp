#include "login_menu.h"


void LoginMenu::load_menu() {


    auto login_label = tgui::Label::create("Minigames");
    auto username_editbox = tgui::EditBox::create();
    auto password_editbox = tgui::EditBox::create();

    auto login_button = tgui::Button::create("Login");
    auto register_button = tgui::Button::create("Don't have an account yet?");
    auto guest_button = tgui::Button::create("Log in as a Guest");
    login_button->onPress([]() { raise_event(Event(Event::LOGIN)); });
    register_button->onPress([]() { raise_event(Event(Event::SHOW_MENU, Menu::REGISTER)); });
    guest_button->onPress([]() { raise_event(Event(Event::GUEST_JOIN)); });

    menu->add(login_label);
    menu->add(username_editbox, "username_editbox");
    menu->add(password_editbox, "password_editbox");
    menu->add(login_button, "login_button");
    menu->add(register_button, "register_button");
    menu->add(guest_button, "guest_button");


    username_editbox->setDefaultText("username");
    password_editbox->setDefaultText("password");

    tgui::String e_width = "13%", e_height = "3.5%", b_width = "10%", b_height = "3.5%";

    login_label->setTextSize(100);
    login_label->getRenderer()->setTextStyle(tgui::TextStyle::Bold);
    login_label->setSize("100%", "20%");
    username_editbox->setSize(e_width, e_height);
    password_editbox->setSize(e_width, e_height);
    login_button->setSize(b_width, b_height);
    register_button->setSize(b_width, b_height);
    guest_button->setSize(b_width, b_height);


    login_label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
    login_label->setPosition("0%", "5%");
    username_editbox->setPosition("43.5%", "35%");
    password_editbox->setPosition("43.5%", "40%");
    login_button->setPosition("45%", "51%");
    register_button->setPosition("45%", "56%");
    guest_button->setPosition("45%", "61%");

    hide();
}

void LoginMenu::hide() {
    menu->setVisible(false);
    menu->get<tgui::EditBox>("username_editbox")->setText("");
    menu->get<tgui::EditBox>("password_editbox")->setText("");
}