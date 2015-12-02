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
/// @file   play.h
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   November, 2015
/// @brief  Play State
//=============================================================================
#pragma once

#include "ball.h"
#include "paddle.h"

/// \brief GameState PLAY
class Play {
  public:
    void init(uint8_t mode);
    void loop();

  private:
    void testRightPaddleCollision();
    void testLeftPaddleCollision();
    void testOut();

    void DoCollision(Ball &b, Paddle &p);

    static const unsigned long OUT_DELAY = 500; // ms

    Ball ball;
    Paddle paddleleft, paddleright;

    unsigned int score_left, score_right;
    unsigned long out_delay;
};
