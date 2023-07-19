#pragma once

#include "data_header.h"

struct SessionData {
    SessionData() = default;

    SessionData(unsigned int width, unsigned int height, int fps) : window_width(width), window_height(height),
                                                                    framerate(fps) {};
    unsigned int window_width = 1920;
    unsigned int window_height = 1080;
    int framerate = 60;
    UserData user = UserData();
    int menu = 0;
    int game = 0;};