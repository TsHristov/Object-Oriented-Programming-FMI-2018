#include <iostream>
using namespace std;

struct Employee {
  char name[100];
  unsigned salary;
  unsigned employee_id;
};

void EnterEmployee(Employee& employee) {
  cout << "Enter Employee information:\n";
  cout << "name= ";
  cin.getline(employee.name, 100);
  cout << "salary= ";
  cin >> employee.salary;
  cout << "id= ";
  cin >> employee.employee_id;
  cin.ignore();
}

void PrintEmployeeSummary(const Employee& employee) {
  cout << employee.name        << "\n";
  cout << employee.salary      << "\n";
  cout << employee.employee_id << "\n";
};

struct Department {
  char name[100];
  unsigned budget;
  unsigned employees_count;
  Employee *employees;
};

void EnterDepartmentEmployees(Department& department) {
  cout << "Count of employees in " << department.name << ": ";
  cin >> department.employees_count;
  cout << department.employees_count;
  cin.ignore();
  department.employees = new (nothrow) Employee[department.employees_count];
  if (!department.employees) {
    return;
  }
  for(int i = 0; i < department.employees_count; i++) {
    EnterEmployee(department.employees[i]);
  }
}

void CreateDepartment(Department& department) {
  cout << "Enter department name:\n";
  cin.getline(department.name, 100);
  cout << "budget= ";
  cin >> department.budget;
  cin.ignore();
  EnterDepartmentEmployees(department);
}

void DestroyDepartment(Department& department) {
  delete[] department.employees;
}

void PrintDepartmentSummary(const Department& department) {
  cout << department.name            << "\t| ";
  cout << department.employees_count << "\t\t| ";
  cout << department.budget          << "\n";
}

struct Organization {
  unsigned departments_count;
  Department *departments;
};

void CreateOrganization(Organization& organization) {
  cout << "Enter number of departments in the organization:";
  cin >> organization.departments_count;
  cin.ignore();
  organization.departments = new (nothrow) Department[organization.departments_count];
  if (!organization.departments) {
    return;
  }
  for (int i=0; i < organization.departments_count; i++) {
    CreateDepartment(organization.departments[i]);
  }
}

void PrintOrganizationSummary(const Organization& organization) {
  cout << "Name" << "\t| " << "Employees"	\
       << "\t| " << "Budget" << "\n";
  for (int i=0; i < organization.departments_count; i++) {
    PrintDepartmentSummary(organization.departments[i]);
  }
}

void DestroyOrganization(Organization& organization) {
  for (int i=0; i < organization.departments_count; i++) {
    DestroyDepartment(organization.departments[i]);
  }
  delete[] organization.departments;
}

int main() {
  Organization organization;

  CreateOrganization(organization);

  PrintOrganizationSummary(organization);

  DestroyOrganization(organization);

  return 0;
}
