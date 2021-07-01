// ==========================================================================
//
// File      : lightController.hpp
// Copyright : Coen Cuppen 2021
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

///@file


#ifndef V1OOPC_EXAMPLES_LIGHTCONTROLLER_HPP
#define V1OOPC_EXAMPLES_LIGHTCONTROLLER_HPP

#include "hwlib.hpp"

class lightController {
private:
    int mode;
    int numberOfLeds;
    bool *brightness;
    bool *red;
    bool *green;
    bool *blue;
public:

    /// \brief
    /// Light_controller constructor
    /// \details
    /// This constructor initializes the mode, brightness level and the color the LEDstrips should have.
    /// The mode should be an integer 1, 2 or 3.
    /// The brightness should be an 8 bit integer in the range 0 and 31.
    /// The colors should be an 8 bit integer in the range of 0 and 255.
    /// Only the 'mode' will be directly added to the private.
    /// The brightness and the colors will first be converted to arrays.
    lightController(int mode, int numberOfLeds, uint8_t brightness, uint8_t red, uint8_t green, uint8_t blue);

    /// \brief
    /// Setting the brightness
    /// \details
    /// This function converts an 8 bit integer to an array of boleans.
    /// The firs 3 bits are automatic '1'. The last 5 bits variable.
    static bool *setArrayBrightness(uint8_t byte);

    /// \brief
    /// Setting the color red
    /// \brief
    /// This function converts an 8 bit integer to an array of boleans.
    static bool *setArrayRed(uint8_t byte);

    /// \brief
    /// Setting the color green
    /// \brief
    /// This function converts an 8 bit integer to an array of boleans.
    static bool *setArrayGreen(uint8_t byte);

    /// \brief
    /// Setting the color blue
    /// \brief
    /// This function converts an 8 bit integer to an array of boleans.
    static bool *setArrayBlue(uint8_t byte);

    /// \brief
    /// Returning 'mode' from private
    /// \details
    /// This function returns 'mode' from private as a const int .
    const int getMode();

    /// \brief
    /// Returning 'numberOfLeds'
    /// \details
    /// This function returns the total number of LED's that are used.
    const int getNumberOfLeds();

    /// \brief
    /// Returning 'brightness' from private
    /// \details
    /// This function returns '*brightness' from private as a const bool*.
    const bool *getBrightness();

    /// \brief
    /// Returning 'red' from private
    /// \details
    /// This function returns '*red' from private as a const bool*.
    const bool *getRed();

    /// \brief
    /// Returning 'green' from private
    /// \details
    /// This function returns '*green' from private as a const bool*.
    const bool *getGreen();

    /// \brief
    /// Returning 'blue' from private
    /// \details
    /// This function returns '*blue' from private as a const bool*.
    const bool *getBlue();
};

#endif //V1OOPC_EXAMPLES_LIGHTCONTROLLER_HPP
