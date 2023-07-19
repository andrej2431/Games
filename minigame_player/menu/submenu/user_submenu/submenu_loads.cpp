#include "user_submenu.h"

void UserSubmenu::user_load_menu() {
    auto pfp_picture = tgui::Picture::create("../menu/submenu/user_submenu/pfp.png");
    pfp_picture->setPosition("16.67%", "0%");
    pfp_picture->setSize("66.66%", "19.7%");

    auto user_label = tgui::Label::create();
    user_label->setSize("100%", "5%");
    user_label->setPosition("0%", "25%");
    user_label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
    user_label->getRenderer()->setTextStyle(tgui::TextStyle::Bold);
    user_label->setTextSize(25);


    auto sign_out_button = tgui::Button::create("Sign Out");
    sign_out_button->onPress([]() { raise_event(Event(Event::LOGOUT)); });

    sign_out_button->setSize("66.66%", "5%");
    sign_out_button->setPosition("16.67%", "33%");

    user->add(pfp_picture);
    user->add(user_label, "user_label");
    user->add(sign_out_button, "sign_out_button");


    hide();
}

void UserSubmenu::guest_load_menu() {
    auto pfp_picture = tgui::Picture::create("../menu/submenu/user_submenu/pfp.png");
    pfp_picture->setPosition("16.67%", "0%");
    pfp_picture->setSize("66.66%", "19.7%");

    auto guest_label = tgui::Label::create("Guest");
    guest_label->setSize("100%", "5%");
    guest_label->setPosition("0%", "25%");
    guest_label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
    guest_label->getRenderer()->setTextStyle(tgui::TextStyle::Bold);
    guest_label->setTextSize(25);


    auto sign_in_button = tgui::Button::create("Sign In");
    sign_in_button->onPress([]() { raise_event(Event(Event::LOGOUT)); });
    sign_in_button->setSize("66.66%", "5%");
    sign_in_button->setPosition("16.67%", "33%");

    guest->add(pfp_picture);
    guest->add(guest_label);
    guest->add(sign_in_button, "sign_in_button");


    hide();
}