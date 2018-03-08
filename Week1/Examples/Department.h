#ifndef __DEPARTMENT_H__
#define __DEPARTMENT_H__
#include "Employee.h"

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

