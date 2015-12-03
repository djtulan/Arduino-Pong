Welcome to my little project Arduino Pong
==============

There are already some versions of pong for Arduino released but no version was satisfing my needs.
So I decided to do my own implementation. I created the game With help of the famous arduino-tvout lib made
by Myles Metzer. At arduino playground there is a small description of it. (see: http://playground.arduino.cc/Main/TVout)

Project Goals:
--------------
- run on most of the Arduino Boards (e.g. Arduino Nano or Uno)
- be as simbple a possible (e.g build up on a Breadboard)
- support for original Atari paddles
- Video & Sound output for usual TV sets

Dependecies:
--------------
- Arduino Libs (from Arduino IDE)
- queezythegreat/arduino-cmake (for building the project)
- arduino-tvout (TVoutBeta1.zip) form (https://code.google.com/p/arduino-tvout/downloads/list)
  or from github (https://github.com/Avamander/arduino-tvout)


Setup and compiling the project:
--------------
- First of all you would need to get the project "queezythegreat/arduino-cmake" on githhub.
  I used it to set up the build environment outside of the arduino IDE.
  Best to clone the repository in parallel to Arduino Pong

- Next you would need to install Arduino IDE to get the arduino libs
- Install arduino-tvout to the arduino libs folder

