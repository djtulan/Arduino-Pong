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
/// @file   ball.cpp
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   November, 2015
/// @brief  Ball class
//=============================================================================
#include "tv.h"

#include "ball.h"

Ball::Ball() {
  xpos = 0;
  ypos = 0;

  vel.x = ballVelocity;
  vel.y = ballVelocity;
}

void Ball::init(uint8_t x, uint8_t y) {
  xpos = x;
  ypos = y;
}

void Ball::setX(uint8_t x) {
  xpos = x;
}

void Ball::setY(uint8_t y) {
  ypos = y;
}

void Ball::changeVelocity(Vector2d &delta) {
  vel.x = delta.x;
  vel.y = delta.y;
}

void Ball::update() {
  xpos += vel.x;
  ypos += vel.y;

  /*
    if (left() <= 0) {
      vel.x *= -1;
      xpos = 0;
      TV.tone(600, 20);
    } else if (right() >= TV.hres() - 1) {
      vel.x *= -1;
      xpos = TV.hres() - 1 - 1;
      TV.tone(600, 20);
    }
  */

  if (top() < 0) {
    vel.y *= -1;
    ypos = 0;
    TV.tone(600, 20);
  } else if (bottom() >= TV.vres() - 1) {
    vel.y *= -1;
    ypos = TV.vres() - 1 - 1;
    TV.tone(600, 20);
  }

  TV.draw_rect(x(), y(), 1, 1, 1, 0);
}

int16_t Ball::x() {
  return xpos;
}

int16_t Ball::y() {
  return ypos;
}

int16_t Ball::left() {
  return x();
}

int16_t Ball::right() {
  return x() + 1;
}

int16_t Ball::top() {
  return y();
}

int16_t Ball::bottom() {
  return y() + 1;
}
