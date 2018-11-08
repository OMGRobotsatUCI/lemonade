
/*
 * Using accelerated motion ("linear speed") in nonblocking mode
 *
 * Copyright (C)2015-2017 Laurentiu Badea
 *
 * This file may be redistributed under the terms of the MIT license.
 * A copy of this license has been included with this distribution in the file LICENSE.
 */
#include <Arduino.h>

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
// Target RPM for cruise speed
#define RPM 450
// Acceleration and deceleration values are always in FULL steps / s^2
#define MOTOR_ACCEL 500
#define MOTOR_DECEL 500

// Microstepping mode. If you hardwired it to save pins, set to the same value here.
#define MICROSTEPS 16
#define DIR 8
#define STEP 9
#define ENABLE 13 // optional (just delete ENABLE from everywhere if not used)

#include <A4988.h>
#define MS1 10
#define MS2 11
#define MS3 12
A4988 stepper(MOTOR_STEPS, DIR, STEP, ENABLE, MS1, MS2, MS3);

void setup() {
    stepper.begin(RPM, MICROSTEPS);
    stepper.enable();
    
    //Set LINEAR_SPEED (accelerated) profile.
    stepper.setSpeedProfile(stepper.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);
}

//TODO: demonstrate nonblocking version so we have some form of multitasking.
void loop() {
  //rotate 720 degrees with 800ms delay before repeating.
  delay(800);
  stepper.rotate(720);

}

