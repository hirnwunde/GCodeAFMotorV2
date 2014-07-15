//------------------------------------------------------------------------------
// 2 Axis GCode-Interpreter for Adafruit motor shields v2
// originally developed by dan@marginallycelver.com 2013-08-30
//------------------------------------------------------------------------------
// Copyright at end of file.
// You can find the original version at http://www.github.com/MarginallyClever/GcodeCNCDemo


//------------------------------------------------------------------------------
// CONSTANTS
//------------------------------------------------------------------------------

//#define VERBOSE (1) // add to get a lot more serial output.
#define VERSION (2) // firmware version
#define BAUD (57600) // How fast is the Arduino talking?
#define MAX_BUF (64) // What is the longest message Arduino can store?
#define STEPS_PER_TURN (200) // depends on your stepper motor. most are 200.
#define MIN_STEP_DELAY (50)
#define MAX_FEEDRATE (500)
#define MIN_FEEDRATE (1)
int LimitSwitchHomeX = 0;
int LimitSwitchHomeY = 0;
int LimitSwitchEndX = 0;
int LimitSwitchEndY = 0;
int bXp_State = 0;
int bXm_State = 0;
int bYp_State = 0;
int bYm_State = 0;



//------------------------------------------------------------------------------
// INCLUDES
//------------------------------------------------------------------------------
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

//------------------------------------------------------------------------------
// GLOBALS
//------------------------------------------------------------------------------
// Initialize Adafruit stepper controller
// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_StepperMotor *mX = AFMS.getStepper(STEPS_PER_TURN, 1); // to motor port #1 (M1 and M2)
Adafruit_StepperMotor *mY = AFMS.getStepper(STEPS_PER_TURN, 2); // to motor port #2 (M3 and M4)

char buffer[MAX_BUF]; // where we store the message until we get a ';'
int sofar; // how much is in the buffer

float px, py; // location X/Y

// speeds
float fr=0; // human version
long step_delay; // machine version

// settings
char mode_abs=1; // absolute mode?


//------------------------------------------------------------------------------
// METHODS
//------------------------------------------------------------------------------

/**
* Set the logical position
* @input npx new position x
* @input npy new position y
*/
void position(float npx,float npy) {
  // here is a good place to add sanity tests
  px=npx;
  py=npy;
}

void release() {
  mX->release();
  mY->release();
}

/**
* write a string followed by a float to the serial line. Convenient for debugging.
* @input code the string.
* @input val the float.
*/
void output(char *code,float val) {
  Serial.print(code);
  Serial.println(val);
}

/**
* print the current position, feedrate, and absolute mode.
*/
void where() {
  output("X",px);
  output("Y",py);
  output("F",fr);
  Serial.println(mode_abs?"ABS":"REL");
}


/**
* display helpful information
*/
void help() {
  Serial.print(F("GcodeCNCDemo2AxisV2 "));
  Serial.println(VERSION);
  Serial.println(F("Commands:"));
  Serial.println(F("G00 [X(steps)] [Y(steps)] [F(feedrate)]; - linear move"));
  Serial.println(F("G01 [X(steps)] [Y(steps)] [F(feedrate)]; - linear move"));
  Serial.println(F("G04 P[seconds]; - delay"));
  Serial.println(F("G28; - move to Home-Position/Origin"));
  Serial.println(F("G90; - absolute mode"));
  Serial.println(F("G91; - relative mode"));
  Serial.println(F("G92 [X(steps)] [Y(steps)]; - change logical position"));
  Serial.println(F("M18; - disable motors"));
  Serial.println(F("M100; - this help message"));
  Serial.println(F("M114; - report position and feedrate"));
  }



/**
* prepares the input buffer to receive a new message and tells the serial connected device it is ready for more.
*/
void ready() {
  sofar=0; // clear input buffer
  Serial.print(F(">")); // signal ready to receive input
}



/**
* First thing this machine does on startup. Runs only once.
*/
void setup() {
  Serial.begin(BAUD); // open coms
  
  AFMS.begin(); // create with the default frequency 1.6KHz
  
  help(); // say hello
  position(0,0); // set staring position
  feedrate(200); // set default speed
 
  
  // limit switches defined at the beginning 
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  
 
  
   ready();
}

void loop() {
  // listen for serial commands
  while(Serial.available() > 0) { // if something is available
    char c=Serial.read(); // get it
    Serial.print(c); // repeat it back so I know you got the message
    if(sofar<MAX_BUF) buffer[sofar++]=c; // store it
    if(buffer[sofar-1]==';') break; // entire message received
  }

  if(sofar>0 && buffer[sofar-1]==';') {
    // we got a message and it ends with a semicolon
    buffer[sofar]=0; // end the buffer so string functions work right
    Serial.print(F("\r\n")); // echo a return character for humans
    processCommand(); // do something with the command
    ready();
  }
}


/**
* This file is part of GcodeCNCDemo.
*
* GcodeCNCDemo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* GcodeCNCDemo is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Foobar. If not, see <http://www.gnu.org/licenses/>.
*/
