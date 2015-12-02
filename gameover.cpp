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
/// @file   gameover.cpp
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   November, 2015
/// @brief  Game Over State
//=============================================================================

#include <Arduino.h>

#include "tv.h"   // tv out instance and includes
#include "pong.h"
#include "menu.h" // next state
#include "play.h" // next state

#include "gameover.h"

void GameOver::init() {
  TV.select_font(font8x8);
  TV.print((TV.hres() - 64) / 2 , 20, "GameOver");
}

void GameOver::loop() {
  if (pong.ButtonPressed() == true) {
    pong.setCurrentState(0);
  }

  TV.delay_frame(1);
}
