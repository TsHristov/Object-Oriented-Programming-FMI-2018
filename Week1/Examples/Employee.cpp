#include <iostream>
#include "Employee.h"

void EnterEmployee(Employee& employee) {
  std::cout << "Enter Employee information:\n";
  std::cout << "name= ";
  std::cin.getline(employee.name, 100);
  std::cout << "salary= ";
  std::cin >> employee.salary;
  std::cout << "id= ";
  std::cin >> employee.employee_id;
  std::cin.ignore();
}

void PrintEmployeeSummary(const Employee& employee) {
  std::cout << employee.name        << "\n";
  std::cout << employee.salary      << "\n";
  std::cout << employee.employee_id << "\n";
};
