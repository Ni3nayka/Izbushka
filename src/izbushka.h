/*
  code write for project:
  https://github.com/Ni3nayka/Izbushka/

  author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka, ReversiTech
  write:  July 2025
  modify: July 2025
*/

#pragma once

#include <Servo.h>

#ifndef SERVO_CENTER_ANGLE_LEFT_DOWN
#define SERVO_CENTER_ANGLE_LEFT_DOWN 90
#endif

#ifndef SERVO_CENTER_ANGLE_LEFT_UP
#define SERVO_CENTER_ANGLE_LEFT_UP 90
#endif

#ifndef SERVO_CENTER_ANGLE_RIGHT_DOWN
#define SERVO_CENTER_ANGLE_RIGHT_DOWN 90
#endif

#ifndef SERVO_CENTER_ANGLE_RIGHT_UP
#define SERVO_CENTER_ANGLE_RIGHT_UP 90
#endif

#ifndef SERVO_MOVE_DELAY
#define SERVO_MOVE_DELAY 15
#endif

#define SERVO_SLOW_MOVE_FUNCTION(real_angle,request_angle) (real_angle==request_angle?0:(real_angle>request_angle?-1:1))

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
    Izbushka::writeServo(0,0,0,0);
  }

  void writeServo(int left_down_servo_angle,
                  int left_up_servo_angle,
                  int right_down_servo_angle,
                  int right_up_servo_angle) {
    Izbushka::left_down_servo.write(left_down_servo_angle+SERVO_CENTER_ANGLE_LEFT_DOWN);
    Izbushka::left_up_servo.write(left_up_servo_angle+SERVO_CENTER_ANGLE_LEFT_UP);
    Izbushka::right_down_servo.write(right_down_servo_angle+SERVO_CENTER_ANGLE_RIGHT_DOWN);
    Izbushka::right_up_servo.write(right_up_servo_angle+SERVO_CENTER_ANGLE_RIGHT_UP);
    Izbushka::left_down_servo_angle = left_down_servo_angle;
    Izbushka::left_up_servo_angle = left_up_servo_angle;
    Izbushka::right_down_servo_angle = right_down_servo_angle;
    Izbushka::right_up_servo_angle = right_up_servo_angle;
  }

  void writeServoSlow(int left_down_servo_angle,
                  int left_up_servo_angle,
                  int right_down_servo_angle,
                  int right_up_servo_angle) {
    while (Izbushka::left_down_servo_angle!=left_down_servo_angle || 
           Izbushka::left_up_servo_angle!=left_up_servo_angle || 
           Izbushka::right_down_servo_angle!=right_down_servo_angle || 
           Izbushka::right_up_servo_angle!=right_up_servo_angle) {
      Izbushka::left_down_servo_angle += SERVO_SLOW_MOVE_FUNCTION(Izbushka::left_down_servo_angle,left_down_servo_angle);
      Izbushka::left_up_servo_angle += SERVO_SLOW_MOVE_FUNCTION(Izbushka::left_up_servo_angle,left_up_servo_angle);
      Izbushka::right_down_servo_angle += SERVO_SLOW_MOVE_FUNCTION(Izbushka::right_down_servo_angle,right_down_servo_angle);
      Izbushka::right_up_servo_angle += SERVO_SLOW_MOVE_FUNCTION(Izbushka::right_up_servo_angle,right_up_servo_angle);
      Izbushka::writeServo(Izbushka::left_down_servo_angle,Izbushka::left_up_servo_angle,Izbushka::right_down_servo_angle,Izbushka::right_up_servo_angle);
      delay(SERVO_MOVE_DELAY);
    }
  }

  void moveForward(int iterations = 1) {
    for (;iterations>0;iterations--) {
      Izbushka::writeServoSlow(10,-20,10,-20);
      Izbushka::writeServoSlow(-10,-20,-10,-20);
      Izbushka::writeServoSlow(-10,20,-10,20);
      Izbushka::writeServoSlow(10,20,10,20);
    }
  }

  void moveBackward(int iterations = 1) {
    for (;iterations>0;iterations--) {
      Izbushka::writeServoSlow(10,20,10,20);
      Izbushka::writeServoSlow(-10,20,-10,20);
      Izbushka::writeServoSlow(-10,-20,-10,-20);
      Izbushka::writeServoSlow(10,-20,10,-20);
    }
  }

  void turnLeft(int iterations = 1) {
    for (;iterations>0;iterations--) {
      Izbushka::writeServoSlow(10,-20,10,20);
      Izbushka::writeServoSlow(-10,-20,-10,20);
      Izbushka::writeServoSlow(-10,20,-10,-20);
      Izbushka::writeServoSlow(10,20,10,-20);
    }
  }

  void turnRight(int iterations = 1) {
    for (;iterations>0;iterations--) {
      Izbushka::writeServoSlow(10,20,10,-20);
      Izbushka::writeServoSlow(-10,20,-10,-20);
      Izbushka::writeServoSlow(-10,-20,-10,20);
      Izbushka::writeServoSlow(10,-20,10,20);
    }
  }

  void jump(int iterations = 1) {
    Izbushka::writeServoSlow(0,0,0,0);
    for (;iterations>0;iterations--) {
      Izbushka::writeServoSlow(20,0,-20,0);
      Izbushka::writeServoSlow(0,0,0,0);
    }
  }

  void stop() {
    Izbushka::writeServoSlow(0,0,0,0);
  }

private:
  Servo left_down_servo, left_up_servo, right_down_servo, right_up_servo;
  int left_down_servo_angle, left_up_servo_angle, right_down_servo_angle, right_up_servo_angle;
};
