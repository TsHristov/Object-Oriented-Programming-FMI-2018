#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include <iostream>

// Дефиниция на структура, която описва служител.
// За целите на примера приемаме, че един
// служител се определя от името му, заплатата му, както и
// от неговия уникален индентификационен номер.
struct Employee {
  char name[100];
  unsigned salary;
  unsigned employee_id;
};

void EnterEmployee(Employee&);

void PrintEmployeeSummary(const Employee&);

#endif
