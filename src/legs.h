/*
  code write for project:
  https://github.com/Ni3nayka/Legs/

  author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka, ReversiTech
  write:  July 2025
  modify: August 2025
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

class Legs {
  public:
    void setupServo(int left_down_servo_pin,
              int left_up_servo_pin,
              int right_down_servo_pin,
              int right_up_servo_pin) {
      Legs::left_down_servo.attach(left_down_servo_pin);
      Legs::left_up_servo.attach(left_up_servo_pin);
      Legs::right_down_servo.attach(right_down_servo_pin);
      Legs::right_up_servo.attach(right_up_servo_pin);
      Legs::writeServo(0,0,0,0);
    }

    void writeServo(int left_down_servo_angle,
                    int left_up_servo_angle,
                    int right_down_servo_angle,
                    int right_up_servo_angle) {
      Legs::left_down_servo.write(left_down_servo_angle+SERVO_CENTER_ANGLE_LEFT_DOWN);
      Legs::left_up_servo.write(left_up_servo_angle+SERVO_CENTER_ANGLE_LEFT_UP);
      Legs::right_down_servo.write(right_down_servo_angle+SERVO_CENTER_ANGLE_RIGHT_DOWN);
      Legs::right_up_servo.write(right_up_servo_angle+SERVO_CENTER_ANGLE_RIGHT_UP);
      Legs::left_down_servo_angle = left_down_servo_angle;
      Legs::left_up_servo_angle = left_up_servo_angle;
      Legs::right_down_servo_angle = right_down_servo_angle;
      Legs::right_up_servo_angle = right_up_servo_angle;
    }

    void writeServoSlow(int left_down_servo_angle,
                    int left_up_servo_angle,
                    int right_down_servo_angle,
                    int right_up_servo_angle) {
      while (Legs::left_down_servo_angle!=left_down_servo_angle || 
            Legs::left_up_servo_angle!=left_up_servo_angle || 
            Legs::right_down_servo_angle!=right_down_servo_angle || 
            Legs::right_up_servo_angle!=right_up_servo_angle) {
        Legs::left_down_servo_angle += SERVO_SLOW_MOVE_FUNCTION(Legs::left_down_servo_angle,left_down_servo_angle);
        Legs::left_up_servo_angle += SERVO_SLOW_MOVE_FUNCTION(Legs::left_up_servo_angle,left_up_servo_angle);
        Legs::right_down_servo_angle += SERVO_SLOW_MOVE_FUNCTION(Legs::right_down_servo_angle,right_down_servo_angle);
        Legs::right_up_servo_angle += SERVO_SLOW_MOVE_FUNCTION(Legs::right_up_servo_angle,right_up_servo_angle);
        Legs::writeServo(Legs::left_down_servo_angle,Legs::left_up_servo_angle,Legs::right_down_servo_angle,Legs::right_up_servo_angle);
        delay(SERVO_MOVE_DELAY);
      }
    }

    void moveForward(int iterations = 1) {
      for (;iterations>0;iterations--) {
        Legs::writeServoSlow(10,-20,10,-20);
        Legs::writeServoSlow(-10,-20,-10,-20);
        Legs::writeServoSlow(-10,20,-10,20);
        Legs::writeServoSlow(10,20,10,20);
      }
    }

    void moveBackward(int iterations = 1) {
      for (;iterations>0;iterations--) {
        Legs::writeServoSlow(10,20,10,20);
        Legs::writeServoSlow(-10,20,-10,20);
        Legs::writeServoSlow(-10,-20,-10,-20);
        Legs::writeServoSlow(10,-20,10,-20);
      }
    }

    void turnLeft(int iterations = 1) {
      for (;iterations>0;iterations--) {
        Legs::writeServoSlow(10,-20,10,20);
        Legs::writeServoSlow(-10,-20,-10,20);
        Legs::writeServoSlow(-10,20,-10,-20);
        Legs::writeServoSlow(10,20,10,-20);
      }
    }

    void turnRight(int iterations = 1) {
      for (;iterations>0;iterations--) {
        Legs::writeServoSlow(10,20,10,-20);
        Legs::writeServoSlow(-10,20,-10,-20);
        Legs::writeServoSlow(-10,-20,-10,20);
        Legs::writeServoSlow(10,-20,10,20);
      }
    }

    void jump(int iterations = 1) {
      Legs::writeServoSlow(0,0,0,0);
      for (;iterations>0;iterations--) {
        Legs::writeServoSlow(20,0,-20,0);
        Legs::writeServoSlow(0,0,0,0);
      }
    }

    void stop() {
      Legs::writeServoSlow(0,0,0,0);
    }

  private:
    Servo left_down_servo, left_up_servo, right_down_servo, right_up_servo;
    int left_down_servo_angle, left_up_servo_angle, right_down_servo_angle, right_up_servo_angle;
};
