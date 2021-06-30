// ==========================================================================
//
// File      : strip.hpp
// Copyright : Coen Cuppen 2021
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

///@file

#ifndef V1OOPC_EXAMPLES_STRIP_HPP
#define V1OOPC_EXAMPLES_STRIP_HPP

#include "lightController.hpp"

class strip {
private:
    lightController lightSetup;
    hwlib::target::pins dataPinNumber;
    hwlib::target::pins clockPinNumber;
public:
    bool bytes0[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    bool bytes1[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    bool brightness0[8] = {1, 1, 1, 0, 0, 0, 0, 0};

    /// \brief
    /// Strip constructor
    /// \details
    /// This is the constructor from the strip class.
    /// The parameters are the lightcontroller class, the data pin number of a LED strip and de clock pin number of a LED strip.
    strip(lightController lightController, hwlib::target::pins dataPinNumber, hwlib::target::pins clockPinNumber);

    /// \brief
    /// sendBytes function
    /// \details
    /// This function converts all 8 bit boolean arrays to electrical pulses.
    /// If the boolean is 1 the clock and data pin will pulse.
    /// if the boolean is 0 only the clock pin will pulse
    void sendBytes(const bool *bytes);

    /// \brief
    /// ledStrip function
    /// \details
    /// This function manages with the parameter 'leds' which LED's should be on.
    /// It also manages the color of the LED's.
    /// Firs the function turns all the LED's of with the ledOff() function.
    /// The function reads the mode that has been given to the lightController class.
    /// If the mode is 1 the first 5 LED's are green, the 6 and 7th LED are yellow and the 8th LED is red.
    /// If the mode is 2 the first 5 LED's are green, the 6 and 7th LED are yellow and changes the first 5 LEDS to yellow.
    /// The 8th LED turns all LED's to red.
    ///
    /// The apa102 LED strip has a protocol to write the amount of LED's and the color.
    /// First the function writes 4 bytes whith only 0's, so the LED strip will listen.
    /// Then it writes the brightness byte and the colors in the order blue green red.
    /// It repeat the last stap for the amount of LED's it has to turn on.
    /// When it's done it writes a byte of only 1's so the LED strip stops listening.
    void ledStrip(int leds);

    /// \brief
    /// ledOff function
    /// \details
    /// This function turns off all the LED's of a LED strip.
    /// The function is similar to the 'ledStrip' function, but it writes only arrays of 0's where normally the color is written.
    void ledOff();
};

#endif //V1OOPC_EXAMPLES_STRIP_HPP
