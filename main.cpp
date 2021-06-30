#include "hwlib.hpp"
#include "MSGEQ7.hpp"

int main(){
    hwlib::wait_ms(200);
    lightController lichtSetup(1, 1, 255, 255, 255);
    MSGEQ7 chip(hwlib::target::pins::d25, hwlib::target::pins::d27, hwlib::target::ad_pins::a0);
    strip ledStrip1(lichtSetup, hwlib::target::pins::d22, hwlib::target::pins::d24);
    strip ledStrip2(lichtSetup, hwlib::target::pins::d26, hwlib::target::pins::d28);
    strip ledStrip3(lichtSetup, hwlib::target::pins::d30, hwlib::target::pins::d32);
    strip ledStrip4(lichtSetup, hwlib::target::pins::d34, hwlib::target::pins::d36);
    strip ledStrip5(lichtSetup, hwlib::target::pins::d38, hwlib::target::pins::d40);
    strip ledStrip6(lichtSetup, hwlib::target::pins::d42, hwlib::target::pins::d44);
    strip ledStrip7(lichtSetup, hwlib::target::pins::d46, hwlib::target::pins::d48);
    chip.equalize(500, ledStrip1, ledStrip2, ledStrip3, ledStrip4, ledStrip5, ledStrip6, ledStrip7);
}
