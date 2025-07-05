/*
  code write for project:
  https://github.com/Ni3nayka/Izbushka/

  author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka
  write:  July 2025
  modify: July 2025
*/

#pragma once

#include <Servo.h>

class Izbushka {
public:
  void setup(int left_down_servo_pin,
             int left_up_servo_pin,
             int right_down_servo_pin,
             int right_up_servo_pin) {
    Izbushka::left_down_servo.attach(left_down_servo_pin);
    Izbushka::left_up_servo.attach(left_up_servo_pin);
    Izbushka::right_down_servo.attach(right_down_servo_pin);
    Izbushka::right_up_servo.attach(right_up_servo_pin);
    Izbushka::writeServo(90, 90, 90, 90);
  }

  void writeServo(int left_down_servo_angle,
                  int left_up_servo_angle,
                  int right_down_servo_angle,
                  int right_up_servo_angle) {
    Izbushka::left_down_servo.write(left_down_servo_angle);
    Izbushka::left_up_servo.write(left_up_servo_angle);
    Izbushka::right_down_servo.write(right_down_servo_angle);
    Izbushka::right_up_servo.write(right_up_servo_angle);
  }

  void moveForward() {

  }

  void moveBackward() {

  }

  void turnLeft() {

  }

  void turnRight() {
    
  }

  void jump() {

  }

private:
  Servo left_down_servo, left_up_servo, right_down_servo, right_up_servo;
};
