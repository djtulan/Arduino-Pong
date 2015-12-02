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
/// @file   pong.cpp
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   November, 2015
/// @brief  Pong Game Main
//=============================================================================
#include <Arduino.h>

#include "tv.h"  // tv out instance and includes

#include "pong.h"

Menu menu;
Play play;
GameOver gameover;

Pong::Pong() {
}

void Pong::setup() {
  randomSeed(analogRead(0));

   //TV.begin(PAL, 128, 96); //for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
   TV.begin(PAL, 136, 96);

  setCurrentState(0);
}

void Pong::loop() {
  switch (current) {
    case 0:
      menu.loop();
      break;

    case 1:
      play.loop();
      break;

    case 2:
      gameover.loop();
      break;
  }
}

void Pong::setCurrentState(uint8_t state) {
  current = state;

  switch (current) {
    case 0:
      menu.init();
      break;

    case 1:
      play.init(playmode);
      break;

    case 2:
      gameover.init();
      break;
  }
}

bool Pong::ButtonPressed() {
  bool ret = false;

  // also wait when button is pressed
  while (digitalRead(6) == 0 || digitalRead(5) == 0) {
    ret = true;
  }

  return ret;
}

int16_t Pong::PaddlePos(uint8_t paddle) {
  uint16_t val = analogRead(paddle ? 0 : 1);;

  // sanity check
  if (val < 460)
    val = 460;

  return val;
}

void Pong::setPlayMode(uint8_t mode) {
  playmode = mode;
}

/// new Pong instance
Pong pong;

void setup() {
  pong.setup(); // setup pong
}

void loop() {
  pong.loop(); // game loop
}

