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
/// @file   paddle.cpp
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   November, 2015
/// @brief  Paddle class
//=============================================================================
#include <Arduino.h>

#include "tv.h"
#include "pong.h"

#include "paddle.h"

Paddle::Paddle() :
  autoplay(false),
  xpos(0), ypos(0) {
}

void Paddle::init(uint8_t x, uint8_t y, uint8_t p, bool autoplay) {
  xpos = x;
  ypos = y;
  paddle = p;
  this->autoplay = autoplay;
}

void Paddle::update() {
  if (autoplay == false) {

    uint16_t val = pong.PaddlePos(paddle);

    // sub offset of resistor network and divide to a rage of 6
    uint16_t calc = (val - 460) / 6;

    // sanity check
    if (calc > TV.vres() - HEIGHT)
      calc = TV.vres() - HEIGHT;

    ypos = calc + HEIGHT / 2;

    // debug
    // TV.print(20 + 80*paddle, 80, (int)ypos);
    // TV.print(20 + 80 * paddle, 85, val);
    // TV.print(20 + 80*paddle, 70, (int)left());
    // TV.print(20 + 80*paddle, 75, (int)left());
    // TV.print(20 + 80*paddle, 80, (int)top());
    // TV.print(20 + 80*paddle, 85, (int)bottom());
  } else {
    ypos = ballpos;

    if (ypos > TV.vres() - HEIGHT / 2)
      ypos = TV.vres() - HEIGHT / 2;
    else if (ypos < HEIGHT / 2)
      ypos = HEIGHT / 2;
  }

  TV.draw_rect(xpos - WIDTH / 2,
               ypos - HEIGHT / 2,
               WIDTH - 1,
               HEIGHT - 1, 1);
}

void Paddle::setBallPos(uint8_t y) {
  ballpos = y;
}

int16_t Paddle::x() {
  return xpos;
}

int16_t Paddle::y() {
  return ypos;
}

int16_t Paddle::left() {
  return x() - WIDTH / 2;
}

int16_t Paddle::right() {
  return x() + WIDTH / 2;
}

int16_t Paddle::top() {
  return y() - HEIGHT / 2;
}

int16_t Paddle::bottom() {
  return y() + HEIGHT / 2;
}
