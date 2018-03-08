#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include <iostream>

struct Employee {
  char name[100];
  unsigned salary;
  unsigned employee_id;
};

void EnterEmployee(Employee&);

void PrintEmployeeSummary(const Employee&);

#endif
