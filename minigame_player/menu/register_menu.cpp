#include "register_menu.h"

void RegisterMenu::load_menu() {

    auto login_label = tgui::Label::create("Minigames");
    auto username_editbox = tgui::EditBox::create();
    auto password1_editbox = tgui::EditBox::create();
    auto password2_editbox = tgui::EditBox::create();

    auto register_button = tgui::Button::create("Register");
    auto login_button = tgui::Button::create("Already have an account?");
    auto guest_button = tgui::Button::create("Log in as a Guest");
    register_button->onPress([]() { raise_event(Event(Event::REGISTER)); });
    login_button->onPress([]() { raise_event(Event(Event::SHOW_MENU, Menu::LOGIN)); });
    guest_button->onPress([]() { raise_event(Event(Event::GUEST_JOIN)); });


    username_editbox->setDefaultText("username");
    password1_editbox->setDefaultText("password");
    password2_editbox->setDefaultText("repeat password");

    menu->add(login_label);
    menu->add(username_editbox, "username_editbox");
    menu->add(password1_editbox, "password1_editbox");
    menu->add(password2_editbox, "password2_editbox");
    menu->add(register_button, "register_button");
    menu->add(login_button, "login_button");
    menu->add(guest_button, "guest_button");

    tgui::String e_width = "13%", e_height = "3.5%", b_width = "10%", b_height = "3.5%";

    login_label->setTextSize(100);
    login_label->getRenderer()->setTextStyle(tgui::TextStyle::Bold);
    login_label->setSize("100%", "20%");
    username_editbox->setSize(e_width, e_height);
    password1_editbox->setSize(e_width, e_height);
    password2_editbox->setSize(e_width, e_height);
    login_button->setSize(b_width, b_height);
    register_button->setSize(b_width, b_height);
    guest_button->setSize(b_width, b_height);


    login_label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
    login_label->setPosition("0%", "5%");
    username_editbox->setPosition("43.5%", "35%");
    password1_editbox->setPosition("43.5%", "40%");
    password2_editbox->setPosition("43.5%", "45%");
    register_button->setPosition("45%", "51%");
    login_button->setPosition("45%", "56%");
    guest_button->setPosition("45%", "61%");

    hide();
}

void RegisterMenu::hide() {
    menu->setVisible(false);
    menu->get<tgui::EditBox>("username_editbox")->setText("");
    menu->get<tgui::EditBox>("password1_editbox")->setText("");
    menu->get<tgui::EditBox>("password2_editbox")->setText("");
}