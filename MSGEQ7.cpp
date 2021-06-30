// ==========================================================================
//
// File      : MSGEQ7.cpp
// Copyright : Coen Cuppen 2021
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================
#include "MSGEQ7.hpp"

MSGEQ7::MSGEQ7(hwlib::target::pins strobe, hwlib::target::pins reset, hwlib::target::ad_pins out) :
    strobePinNumber(strobe),
    resetPinNumber(reset),
    outPinNumber(out) {}

int * MSGEQ7::getAmplitude(int devider) {
    auto strobe = hwlib::target::pin_out(strobePinNumber);
    auto reset = hwlib::target::pin_out(resetPinNumber);
    auto out = hwlib::target::pin_adc(outPinNumber);
    static int amplitude[8];

    reset.write(1);
    hwlib::wait_ns(100);
    reset.write(0);

    for (uint8_t i = 0; i < 7; i++) {
        strobe.write(0);
        hwlib::wait_us(36);
        out.refresh();
        amplitude[i] = out.read() / devider;
        strobe.write(1);
        hwlib::wait_us(36);
    }
    return amplitude;

}

void MSGEQ7::equalize(int devider, strip led0, strip led1, strip led2, strip led3, strip led4, strip led5, strip led6) {
    for (;;) {
        int *y = getAmplitude(devider);
        led0.ledStrip(y[0]);
        led1.ledStrip(y[1]);
        led2.ledStrip(y[2]);
        led3.ledStrip(y[3]);
        led4.ledStrip(y[4]);
        led5.ledStrip(y[5]);
        led6.ledStrip(y[6]);
    }
}