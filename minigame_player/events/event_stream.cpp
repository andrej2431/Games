#include "event_stream.h"

void raise_event(const Event &event) {
    EventStream::getInstance().push_event(event);

}

Event EventStream::get_event() {
    if (event_queue.empty())
        return {};
    Event event = event_queue.front();
    event_queue.pop();
    return event;
}