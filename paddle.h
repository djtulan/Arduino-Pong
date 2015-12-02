//=============================================================================
// *** Arduino Pong ***
// Copyright (c) Robert Grasböck, All rights reserved.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3.0 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library.
//=============================================================================
/// @file   paddle.h
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   November, 2015
/// @brief  Paddle class
//=============================================================================
#pragma once

// Let's create a `Paddle` class, similar to `Ball`.
class Paddle {
    friend class Play;

  public:
    Paddle();

    void init(uint8_t x, uint8_t y, uint8_t p, bool autoplay);

    void update();

    int16_t x();
    int16_t y();
    int16_t left();
    int16_t right();
    int16_t top();
    int16_t bottom();

    void setBallPos(uint8_t y);

  private:
    bool autoplay;

    uint8_t xpos, ypos, paddle, ballpos;

    static const uint8_t WIDTH = 2;
    static const uint8_t HEIGHT = 7;
};
