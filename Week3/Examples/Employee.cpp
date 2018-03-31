#include <iostream>
#include <string.h>
#include "Employee.h"

// Описание:
//   Конструктор на обекта. Служи за инициализация на полетата на обекта.
Employee :: Employee(const char *name, unsigned salary, unsigned id) {
  std::cout << "Constructor called\n";
  this->name   = new char[strlen(name) + 1];
  strcpy(this->name, name);
  this->salary = salary;
  this->id     = id;
}

// Описание:
//   Copy конструктор. Неговата функция е да инициалзира текущия обект,
//   въз основа на друг вече съществуващ (от същия клас).
// Пример:
//   Employee first("first", 1, 2);
//   Employee second(first);  <-- обръщение към copy конструктора
//   Employee third = second; <-- обръщение към copy конструктора
Employee :: Employee (const Employee& other) {
  std::cout << "Copy Constructor called\n";
  this->name   = new char[strlen(other.name) + 1];
  strcpy(this->name, other.name);
  this->salary = other.salary;
  this->id     = other.id;
}

// Описание:
//   Копиращ оператор за присовяване. Служи за преинициализация на текущия обект
//   с друг вече съществуващ обект (от същия клас).
// Пример:
//   Employee first("first", 1, 2);
//   Employee second("second", 2, 3);
//   first = second; <---- тук се прави обръщение към operator=
Employee& Employee :: operator=(const Employee& other) {
  std::cout << "Copy assignment operator called\n";
  if(this != &other) {
    delete[] name;
    this->name   = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->salary = other.salary;
    this->id     = id;
    return *this;
  }
  return *this;
}

// Описание:
//   Деструктор. Служи за освобождаване на заетите ресурси от обекта.
Employee :: ~Employee() {
  std::cout << "Destructor called\n";
  delete[] name;
}


