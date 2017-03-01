/*
 Name:		TwinkeStepper.ino
 Created:	1/3/2017 5:37:27 PM
 Author:	HARRISON WELCH
 Last Edit: 03-01-2017 3:06:46 PM
*/

//HardwareSerial Serial;
#include <HardwareSerial.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

char val;
const int ONE_HUNDRED = 100;

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

	playF();
	playG();
	playA();
	playB();
	playC();
	playD();
	playE();
	playF2();
	delay(1000);

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
	stepper->step(15, dir, DOUBLE);
	delay(ONE_HUNDRED);
	if (dir == 1) { dir = 2; }
	else { dir = 1; }
	stepper->step(15, dir, DOUBLE);
	delay(ONE_HUNDRED);
}

void playF() {
	play(Stepper4, BACKWARD);
}
void playG() {
	play(Stepper4, FORWARD);
}
void playA() {
	play(Stepper3, BACKWARD);
}
void playB() {
	play(Stepper3, FORWARD);
}
void playC() {
	play(Stepper2, BACKWARD);
}
void playD() {
	play(Stepper2, FORWARD);
}
void playE() {
	play(Stepper1, BACKWARD);
}
void playF2() {
	play(Stepper1, FORWARD);
}
void playG2() {}
