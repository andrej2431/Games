#pragma once

#include "menu.h"

class NotificationMenu : public Menu {
public:
    NotificationMenu();

    std::string get_name() override { return "notification_menu"; };

    void display_warning(const std::string &);

    void destroy_oldest_warning();

    void destroy_all_warnings();

private:
    tgui::Group::Ptr warning_group;
    std::vector<tgui::Label::Ptr> warnings_displayed;
    tgui::Timer::Ptr warning_destruction_timer;
};

