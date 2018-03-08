#ifndef __DEPARTMENT_H__
#define __DEPARTMENT_H__
#include "Employee.h"

// Дефиниция на структура, която описва депарамент в
// организация. За целите на примера приемаме, че един
// департамент се определя от името му, бюджет, брой на
// неговите служители и самите служители, които работят в него.
struct Department {
  char name[100];
  unsigned budget;
  unsigned employees_count;
  Employee *employees;
};

void EnterDepartmentEmployees(Department&);

void CreateDepartment(Department&);

void PrintDepartmentSummary(const Department&);

void DestroyDepartment(Department&);

#endif

