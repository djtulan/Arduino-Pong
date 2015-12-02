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
/// @file   pong.h
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   November, 2015
/// @brief  Pong Game Main
//=============================================================================

#pragma once

#include "menu.h"
#include "play.h"
#include "gameover.h"

/// \brief Game PONG
class Pong {
  public:
    Pong();

    /**
     * @brief run setup for pong game
     */
    void setup();

    /**
     * @brief main game loop
     */
    void loop();

    /**
     * @brief set new game state
     * @param s new state
     */
    void setCurrentState(uint8_t state);

    /**
     * @brief return true when button is pressed
     * @return bool true ... if one of the atari paddle buttons is pressed
     */
    bool ButtonPressed();

    /**
     * @brief return analog read amout if the sensor
     * @param [in] paddle which paddle?
     * @return 460 ... 1023
     */
    int16_t PaddlePos(uint8_t paddle);

    /**
     * @brief set the play mode
     * @param [in] mode 0 -> 2 playermode / 1 -> player vs. computer
     */
    void setPlayMode(uint8_t mode);

  private:
    uint8_t current;  ///< current game state
    uint8_t playmode; ///< play mode
};

extern Pong pong; // instance of pong
