/*
 Name:		TwinkeStepper.ino
 Created:	1/3/2017 5:37:27 PM
 Author:	HARRISON WELCH
 Last Edit: 04-08-2017 4:04:00 PM
*/

//HardwareSerial Serial;
#include <HardwareSerial.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

char val;
const int ONE_HUNDRED = 100;
const int std_delay_time = 500;//ms
const int std_step_amt = 20;//steps


Adafruit_MotorShield top(0x60);//init top    shield
Adafruit_MotorShield bot(0x61);//init bottom shield

Adafruit_StepperMotor *Stepper1 = top.getStepper(200, 1);
Adafruit_StepperMotor *Stepper2 = top.getStepper(200, 2);
Adafruit_StepperMotor *Stepper3 = bot.getStepper(200, 1);
Adafruit_StepperMotor *Stepper4 = bot.getStepper(200, 2);

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	top.begin();
	bot.begin();
	Serial.println("Good to go!");
}

// the loop function runs over and over again until power down or reset
void loop() {
  
  /*Twinkle-Twinkle Little Star
   * GGDDEED
   * CCBBAAG
   * DDCCBBA
   * DDCCBBA
   * GGDDEED
   * CCBBAAG
   * 
   * Translate to my numbered functions
   * 
   * 7744554
   * 3322117
   * 4433221
   * 4433221
   * 7744554
   * 3322117
   */

  play7();play7();play4();play4();play5();play5();play4();delay(500);
  play3();play3();play2();play2();play1();play1();play7();delay(500);
  play4();play4();play3();play3();play2();play2();play1();delay(500);
  play4();play4();play3();play3();play2();play2();play1();delay(500);
  play7();play7();play4();play4();play5();play5();play4();delay(500);
  play3();play3();play2();play2();play1();play1();play7();delay(500);
   
  //simple up-scale//
  /*
  play1();//6
  play2();//5
  play3();//1
  play4();//2
  play5();//3
  play6();//4
  play7();//8
  play8();//7 
  */
  /*
  //old code from be
	playF();//1
	playG();//2
	playA();//3
	playB();//4
	playC();//5
	playD();//6
	playE();//7
	playF2();//8
	*/
  
	delay(1000); //testing line

}

void play(Adafruit_StepperMotor *stepper, int steps, int dir, int style, int delayTime) {
	//Serial.println("dir before swap is :" + dir);
	stepper->step(steps, dir, style);
	delay(delayTime);
	if (dir == 1) { dir = 2; }
	else { dir = 1; }
	//Serial.println("dir after swap is :" + dir);
	stepper->step(steps, dir, style);
	delay(delayTime);

}
void play(Adafruit_StepperMotor *stepper, int steps, int dir, int style) {
	stepper->step(steps, dir, style);
	delay(100);
	if (dir == 1) { dir = 2; }
	else { dir = 1; }
	stepper->step(steps, dir, style);
	delay(100);

}
void play(Adafruit_StepperMotor *stepper, int steps, int dir) {
	stepper->step(steps, dir, DOUBLE);
	delay(100);
	if (dir == 1) { dir = 2; }
	else { dir = 1; }
	stepper->step(steps, dir, DOUBLE);
	delay(100);
}
void play(Adafruit_StepperMotor *stepper, int dir) {
	stepper->step(std_step_amt, dir, DOUBLE);
	delay(std_delay_time);
	if (dir == 1) { dir = 2; }
	else { dir = 1; }
	stepper->step(std_step_amt, dir, DOUBLE);
	delay(std_delay_time);
}

//TODO: sort this list of functions

void play3() {
	play(Stepper4, BACKWARD);
}
void play4() {
	play(Stepper4, FORWARD);
}
void play5() {
	play(Stepper3, BACKWARD);
}
void play6() {
	play(Stepper3, FORWARD);
}
void play2() {
	play(Stepper2, BACKWARD);
}
void play1() {
	play(Stepper2, FORWARD);
}
void play8() {
	play(Stepper1, BACKWARD);
}
void play7() {
	play(Stepper1, FORWARD);
}
void playG2() {}
