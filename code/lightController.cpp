// ==========================================================================
//
// File      : lightController.cpp
// Copyright : Coen Cuppen 2021
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================
#include "lightController.hpp"

lightController::lightController(int mode, uint8_t brightness, uint8_t red, uint8_t green, uint8_t blue) :
        mode(mode),
        brightness(setArrayBrightness(brightness)),
        red(setArrayRed(red)),
        green(setArrayGreen(green)),
        blue(setArrayBlue(blue)) {}


bool * lightController::setArrayBrightness(uint8_t byte) {
    static bool byte_list[8];
    byte_list[0] = 1;
    byte_list[1] = 1;
    byte_list[2] = 1;
    for (uint8_t i = 0; i < 5; i++) {
        if (1 << i & byte) {
            byte_list[7 - i] = 1;
        } else {
            byte_list[7 - i] = 0;
        }
    }
    return byte_list;
}

bool * lightController::setArrayRed(uint8_t byte) {
    static bool byte_list[8];
    for (uint8_t i = 0; i < 8; i++) {
        if (1 << i & byte) {
            byte_list[7 - i] = 1;
        } else {
            byte_list[7 - i] = 0;
        }
    }
    return byte_list;
}

bool * lightController::setArrayGreen(uint8_t byte) {
    static bool byte_list[8];
    for (uint8_t i = 0; i < 8; i++) {
        if (1 << i & byte) {
            byte_list[7 - i] = 1;
        } else {
            byte_list[7 - i] = 0;
        }
    }
    return byte_list;
}

bool * lightController::setArrayBlue(uint8_t byte) {
    static bool byte_list[8];
    for (uint8_t i = 0; i < 8; i++) {
        if (1 << i & byte) {
            byte_list[7 - i] = 1;
        } else {
            byte_list[7 - i] = 0;
        }
    }
    return byte_list;
}

const int lightController::getMode() {
    return mode;
}

const bool * lightController::getBrightness() {
    return brightness;
}

const bool * lightController::getRed() {
    return red;
}

const bool * lightController::getGreen() {
    return green;
}

const bool * lightController::getBlue() {
    return blue;
}