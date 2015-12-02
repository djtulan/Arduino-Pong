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
/// @file   play.cpp
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   November, 2015
/// @brief  Play State
//=============================================================================

#include <Arduino.h>

#include "tv.h"       // tv out instance and includes
#include "pong.h"
#include "gameover.h" // next state

#include "play.h"

#define LEFT_SCORE_X     (TV.hres() / 2 - 10 - 4)
#define RIGHT_SCORE_X    (TV.hres() / 2 + 10 + 1)
#define SCORE_Y          4

void Play::init(uint8_t mode) {
  TV.select_font(font4x6);

  score_left = score_right = 0;

  paddleleft.init(6, (TV.vres() - 1) / 2, 0, false);
  paddleright.init(TV.hres() - 1 - 6, (TV.vres() - 1) / 2, 1, (mode) ? true : false);

  ball.init(40, 40);

  out_delay = 0;
}

void Play::loop() {
  TV.clear_screen();

  TV.draw_line(0,          0, 0,                TV.vres() - 1, 1);
  TV.draw_line(TV.hres() - 1, 0, TV.hres() - 1, TV.vres() - 1, 1);

  // draw net
  for (unsigned char i = 1; i < TV.vres() - 4; i += 6) {
    TV.draw_line(TV.hres() / 2, i, TV.hres() / 2, i + 3, 1);
  }

  if (out_delay && (millis() - out_delay) < OUT_DELAY) {
    // do nothing
  } else {
    out_delay = 0;

    // ball update
    ball.update();
  }

  // update for autplay mode
  paddleleft.setBallPos(ball.x());
  paddleright.setBallPos(ball.y());

  paddleleft.update();
  paddleright.update();

  testRightPaddleCollision();
  testLeftPaddleCollision();

  // test if ball is out
  testOut();

  TV.print(LEFT_SCORE_X, SCORE_Y, score_left);
  TV.print(RIGHT_SCORE_X, SCORE_Y, score_right);

  // game over
  if (score_left >= 11 || score_right >= 11)
    pong.setCurrentState(2);

  TV.delay_frame(1);
}

void Play::testRightPaddleCollision() {
  if (ball.right() >= paddleright.left() &&
      ball.right() <= paddleright.right() &&
      ball.bottom() >= paddleright.top() &&
      ball.top() <= paddleright.bottom()) {

    ball.setX(paddleright.left() - 2);
    DoCollision(ball, paddleleft);
  }
}

void Play::testLeftPaddleCollision() {
  if (ball.left() <= paddleleft.right() &&
      ball.left() >= paddleleft.left() &&
      ball.bottom() >= paddleleft.top() &&
      ball.top() <= paddleleft.bottom()) {

    ball.setX(paddleleft.right() + 1);
    DoCollision(ball, paddleleft);
  }
}

void Play::DoCollision(Ball &b, Paddle &p) {

  // play sound
  TV.tone(800, 20);

  // reverse speed of ball
  b.vel.x = b.vel.x * -1;

  int8_t diff = b.y() - p.y();

  int8_t multi = 1;

  if (diff < 0)
    multi = -1;

  switch (abs(diff)) {
    case 0:
      b.vel.x *= 1.0;
      break;

    case 1:
      b.vel.x *= 1.1;
      break;

    case 2:
      b.vel.x *= 1.1;
      break;

    case 3:
      b.vel.x *= 1.2;
      break;

    case 4:
      b.vel.x *= 1.2;
      break;
  }
}

void Play::testOut(void) {
  Vector2d newvel;
  bool out = false;

  // ball out left?
  if (ball.left() <= 0) {
    score_right ++;
    out = true;
    newvel.x = -Ball::ballVelocity;
    newvel.y = Ball::ballVelocity;

    // ball out right?
  } else if (ball.right() >= TV.hres() - 1) {
    score_left ++;
    out = true;
    newvel.x = Ball::ballVelocity;
    newvel.y = Ball::ballVelocity;
  }

  // out flag?
  if (out == true) {
    ball.setX(TV.hres() / 2);
    TV.tone(100, 300);

    out_delay = millis();

    ball.changeVelocity(newvel);
  }
}



