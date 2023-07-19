#include "notification_menu.h"

NotificationMenu::NotificationMenu() : Menu() {
    warning_group = tgui::Group::create();
    warning_group->setSize("25%", "25%");
    warning_group->setPosition("37.5%", "0%");

    warning_destruction_timer = tgui::Timer::create([&]() { destroy_oldest_warning(); }, 2000);
    warning_destruction_timer->setEnabled(false);
    menu->add(warning_group);

}

void NotificationMenu::destroy_oldest_warning() {
    if (warnings_displayed.empty()) {
        warning_destruction_timer->setEnabled(false);
        return;
    }

    warning_group->remove(warnings_displayed[0]);
    warnings_displayed.erase(warnings_displayed.begin());

    if (warnings_displayed.empty()) {
        warning_destruction_timer->setEnabled(false);
        return;
    }

}

void NotificationMenu::destroy_all_warnings() {
    warning_destruction_timer->setEnabled(false);
    for (const auto &warning: warnings_displayed) {
        warning_group->remove(warning);
    }
    warnings_displayed.clear();
}

void NotificationMenu::display_warning(const std::string &message) {
    if (warnings_displayed.size() >= 5)
        return;
    auto height = menu->getSize().y / 25, padding = menu->getSize().y / 100;

    for (const auto &label: warnings_displayed) {
        label->setPosition("0%", label->getPosition().y + padding + height);
    }

    auto warning_label = tgui::Label::create(message);

    warning_label->setSize("100%", height);
    warning_label->setPosition("0%", "3%");
    warning_label->ignoreMouseEvents(true);
    warning_label->getRenderer()->setBackgroundColor(tgui::Color(205, 149, 149, 220));
    warning_label->getRenderer()->setTextColor(tgui::Color(160, 75, 75, 255));
    warning_label->setTextSize(15);


    warnings_displayed.push_back(warning_label);
    warning_group->add(warning_label);
    warning_destruction_timer->setEnabled(true);
}