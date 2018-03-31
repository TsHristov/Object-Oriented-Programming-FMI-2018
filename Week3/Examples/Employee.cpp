#include <iostream>
#include <string.h>
#include "Employee.h"


Employee :: Employee(const char *name, unsigned salary, unsigned id) {
  std::cout << "Constructor called\n";
  this->name   = new char[strlen(name) + 1];
  strcpy(this->name, name);
  this->salary = salary;
  this->id     = id;
}


Employee :: Employee (const Employee& other) {
  std::cout << "Copy Constructor called\n";
  this->name   = new char[strlen(other.name) + 1];
  strcpy(this->name, other.name);
  this->salary = other.salary;
  this->id     = other.id;
}


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


Employee :: ~Employee() {
  std::cout << "Destructor called\n";
  delete[] name;
}


