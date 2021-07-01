// ==========================================================================
//
// File      : strip.cpp
// Copyright : Coen Cuppen 2021
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================
#include "strip.hpp"


strip::strip(lightController lightSetup, hwlib::target::pins dataPinNumber, hwlib::target::pins clockPinNumber) :
        lightSetup(lightSetup),
        dataPinNumber(dataPinNumber),
        clockPinNumber(clockPinNumber) {}


void strip::sendBytes(const bool *bytes) {
    auto data_pin = hwlib::target::pin_out(dataPinNumber);
    auto clock_pin = hwlib::target::pin_out(clockPinNumber);
    for (unsigned int i = 0; i < 8; i++) {
        switch (bytes[i]) {
            case 0:
                data_pin.write(false);
                break;
            case 1:
                data_pin.write(true);
                break;
        }
        clock_pin.write(true);
        hwlib::wait_ns(1);
        clock_pin.write(false);
    }
}

void strip::ledStrip(int leds) {
    ledOff();
    int mode = lightSetup.getMode();
    switch (mode) {
        case 1:
            sendBytes(bytes0);
            sendBytes(bytes0);
            sendBytes(bytes0);
            sendBytes(bytes0);

            for (int i = 1; i <= leds; ++i) {
                if (i > 0 && i < (lightSetup.getNumberOfLeds() / 8 * 6)) {
                    sendBytes(lightSetup.getBrightness());
                    sendBytes(bytes0);
                    sendBytes(bytes1);
                    sendBytes(bytes0);
                }
                if (i > (lightSetup.getNumberOfLeds() / 8 * 5) && i <= (lightSetup.getNumberOfLeds() / 8 * 7)) {
                    sendBytes(lightSetup.getBrightness());
                    sendBytes(bytes0);
                    sendBytes(bytes1);
                    sendBytes(bytes1);
                }
                if (i > (lightSetup.getNumberOfLeds() / 8 * 7) && i <= lightSetup.getNumberOfLeds()) {
                    sendBytes(lightSetup.getBrightness());
                    sendBytes(bytes0);
                    sendBytes(bytes0);
                    sendBytes(bytes1);
                }

            }
            sendBytes(bytes1);
            break;

        case 2:
            sendBytes(bytes0);
            sendBytes(bytes0);
            sendBytes(bytes0);
            sendBytes(bytes0);

            for (int i = 1; i <= leds; ++i) {
                if (leds > 0 && leds < (lightSetup.getNumberOfLeds() / 8 * 6)) {
                    sendBytes(lightSetup.getBrightness());
                    sendBytes(bytes0);
                    sendBytes(bytes1);
                    sendBytes(bytes0);
                }
                if (leds > (lightSetup.getNumberOfLeds() / 8 * 5) && leds <= (lightSetup.getNumberOfLeds() / 8 * 7)) {
                    sendBytes(lightSetup.getBrightness());
                    sendBytes(bytes0);
                    sendBytes(bytes1);
                    sendBytes(bytes1);
                }
                if (leds > (lightSetup.getNumberOfLeds() / 8 * 7) && leds <= lightSetup.getNumberOfLeds()) {
                    sendBytes(lightSetup.getBrightness());
                    sendBytes(bytes0);
                    sendBytes(bytes0);
                    sendBytes(bytes1);
                }

            }
            sendBytes(bytes1);
            break;

        case 3:
            sendBytes(bytes0);
            sendBytes(bytes0);
            sendBytes(bytes0);
            sendBytes(bytes0);

            for (int i = 1; i <= leds; ++i) {
                sendBytes(lightSetup.getBrightness());
                sendBytes(lightSetup.getBlue());
                sendBytes(lightSetup.getGreen());
                sendBytes(lightSetup.getRed());
            }
            sendBytes(bytes1);
            break;
    }
}

void strip::ledOff() {
    sendBytes(bytes0);
    sendBytes(bytes0);
    sendBytes(bytes0);
    sendBytes(bytes0);
    for (int i = 0; i < 8; ++i) {
        sendBytes(brightness0);
        sendBytes(bytes0);
        sendBytes(bytes0);
        sendBytes(bytes0);
    }
    sendBytes(bytes1);
    sendBytes(bytes1);
    sendBytes(bytes1);
    sendBytes(bytes1);

}