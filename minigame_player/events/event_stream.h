#pragma once

#include <queue>
#include <iostream>
#include <string>
#include <utility>
#include "warning.h"


struct Event {

    enum : int {
        NONE = 0, LOGIN, REGISTER, GUEST_JOIN, LOGOUT, SHOW_MENU,
        START_GAME, CLOSE_GAME,
        UPDATE_LEADERBOARD,
        WARNING,
    };


    Event(int new_type, int new_value, std::string new_message) :
            type(new_type), value(new_value), message(std::move(new_message)) {};

    Event(int new_type, int new_value) : Event(new_type, new_value, "") {};

    explicit Event(int new_type) : Event(new_type, 0, "") {};

    Event() : Event(0, 0, "") {};

    int type;
    int value;
    std::string message;


};

class EventStream {
public:
    static EventStream &getInstance() {
        static EventStream instance;
        return instance;
    }

    void push_event(const Event &event) { event_queue.push(event); }

    Event get_event();

private:
    EventStream() = default;

    std::queue<Event> event_queue;


public:
    void operator=(EventStream const &) = delete;
};

void raise_event(const Event &event);
