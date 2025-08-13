/*
  code write for project:
  https://github.com/Ni3nayka/Izbushka/

  author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka, ReversiTech
  write:  July 2025
  modify: August 2025
*/


// optional
// #define SERVO_CENTER_ANGLE_LEFT_DOWN 60
// #define SERVO_CENTER_ANGLE_LEFT_UP 110
// #define SERVO_CENTER_ANGLE_RIGHT_DOWN 120
// #define SERVO_CENTER_ANGLE_RIGHT_UP 90

// подключаем библиотеку
#include "izbushka.h"

void setup() {
  Serial.begin(9600);    // Инициализируем монитор порта для отладки
  izbushka.setupServo(8,9,10,11);
  izbushka.setupUltrasonar(A1,A0);
}

void loop () {
  basic();
}

void basic() {
  if (0) bluetoothRun();
  else if (izbushka.ultrasonar_enable==true) ultrasonarRun();
  else dance();
}

void bluetoothRun() {

}

void ultrasonarRun() {
  int distance = izbushka.getUltrasonar();
  Serial.println(distance);
}

void dance() {
  Serial.println("start dance");
  delay(5000);
  izbushka.jump(5);
  izbushka.moveForward(5);
  izbushka.moveBackward(5);
  izbushka.turnLeft(5);
  izbushka.turnRight(5);
  izbushka.stop();
  Serial.println("end dance");
}

