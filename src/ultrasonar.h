/*
  code write for project:
  https://github.com/Ni3nayka/Izbushka/

  author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka, ReversiTech
  write:  August 2025
  modify: August 2025

  links:
  https://arduinomaster.ru/datchiki-arduino/ultrazvukovoj-dalnomer-hc-sr04/
*/

#pragma once

#define ULTRASONAR_MAX_DISTANCE 300

class Ultrasonar {
  public:
    bool ultrasonar_enable;
    void setupUltrasonar(int trigger_pin, int echo_pin=-1) {
      Ultrasonar::trigger_pin = trigger_pin;
      Ultrasonar::echo_pin = echo_pin;
      if (Ultrasonar::echo_pin!=-1) {
        pinMode(Ultrasonar::trigger_pin, OUTPUT);
        pinMode(Ultrasonar::echo_pin, INPUT);
      }
      else {
        Ultrasonar::echo_pin = Ultrasonar::trigger_pin;
      }
      Ultrasonar::ultrasonar_enable = 1;
      getUltrasonar();
      getUltrasonar();
      getUltrasonar();
    }

    int getUltrasonar() {
      if (Ultrasonar::trigger_pin==Ultrasonar::echo_pin) {
        pinMode(Ultrasonar::trigger_pin, OUTPUT);
      }
      digitalWrite(Ultrasonar::trigger_pin, LOW);
      delayMicroseconds(5);
      digitalWrite(Ultrasonar::trigger_pin, HIGH);
      delayMicroseconds(10);
      digitalWrite(Ultrasonar::trigger_pin, LOW);
      if (Ultrasonar::trigger_pin==Ultrasonar::echo_pin) {
        pinMode(Ultrasonar::trigger_pin, INPUT);
      }
      int cm = pulseIn(Ultrasonar::echo_pin, HIGH) / 58;
      if (cm<0) cm = ULTRASONAR_MAX_DISTANCE;
      cm = constrain(cm,0,ULTRASONAR_MAX_DISTANCE);
      delay(100);
      Ultrasonar::ultrasonar_enable = cm!=0;
      return cm;
    }

  private:
    int trigger_pin, echo_pin;
};
