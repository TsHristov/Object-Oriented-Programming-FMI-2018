#include "Department.h"

void EnterDepartmentEmployees(Department& department) {
  std::cout << "Count of employees in " << department.name << ": ";
  std::cin >> department.employees_count;
  std::cout << department.employees_count;
  std::cin.ignore();
  department.employees = new (std::nothrow) Employee[department.employees_count];
  if (!department.employees) {
    return;
  }
  for(int i = 0; i < department.employees_count; i++) {
    EnterEmployee(department.employees[i]);
  }
}

void CreateDepartment(Department& department) {
  std::cout << "Enter department name:\n";
  std::cin.getline(department.name, 100);
  std::cout << "budget= ";
  std::cin >> department.budget;
  std::cin.ignore();
  EnterDepartmentEmployees(department);
}

void DestroyDepartment(Department& department) {
  delete[] department.employees;
}

void PrintDepartmentSummary(const Department& department) {
  std::cout << department.name            << "\t| ";
  std::cout << department.employees_count << "\t\t| ";
  std::cout << department.budget          << "\n";
}
