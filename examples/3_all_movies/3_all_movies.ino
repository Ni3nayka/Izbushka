/*
  code write for project:
  https://github.com/Ni3nayka/Izbushka/

  author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka
  write:  July 2025
  modify: July 2025
*/

// подключаем библиотеку
#include "izbushka.h"

Izbushka izbushka;

void setup() {
  Serial.begin(9600);    // Инициализируем монитор порта для отладки
  izbushka.setup(10,11,12,13);
}

void loop () {
    
}

// ПРИМЕР ЕЩЕ В РАЗРАБОТКЕ
