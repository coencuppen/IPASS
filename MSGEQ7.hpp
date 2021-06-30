// ==========================================================================
//
// File      : MSGEQ7.hpp
// Copyright : Coen Cuppen 2021
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================

///@file

#ifndef V1OOPC_EXAMPLES_MSGEQ7_HPP
#define V1OOPC_EXAMPLES_MSGEQ7_HPP

#include "strip.hpp"

class MSGEQ7 {
private:
    hwlib::target::pins strobePinNumber;
    hwlib::target::pins resetPinNumber;
    hwlib::target::ad_pins outPinNumber;

public:

    /// \brief
    /// MSGEQ7 constructor.
    /// \details
    /// Constructor for the class MSGEQ7.
    /// The parameters are the strobe pin number, reset pin number and the out pin number.
    /// The 'strobe' and 'reset' pins are both digital out pins. the 'out' pin is a analog read pin.
    MSGEQ7(hwlib::target::pins strobe, hwlib::target::pins reset, hwlib::target::ad_pins out);

    /// \brief
    /// getAmplitude function
    /// \details
    /// This function returns an array of integers from 0 to 8.
    /// The first integer is the first frequency band.
    /// The values are divided by the 'devider' parameter (usually 500) so the max readings are around 8 and the lowest readings are 0.
    int *getAmplitude(int devider);

    /// \brief
    /// equalize function
    /// \details
    /// This function is the main loop of the program.
    /// In this function the 'getAmplitude()' get called and the integers in the array are given to the correct LED strip.
    void equalize(int devider, strip led0, strip led1, strip led2, strip led3, strip led4, strip led5, strip led6);
};


#endif //V1OOPC_EXAMPLES_MSGEQ7_HPP
