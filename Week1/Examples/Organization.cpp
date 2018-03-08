#include "Organization.h"

void CreateOrganization(Organization& organization) {
  std::cout << "Enter number of departments in the organization:";
  std::cin >> organization.departments_count;
  std::cin.ignore();
  organization.departments = new (std::nothrow) Department[organization.departments_count];
  if (!organization.departments) {
    return;
  }
  for (int i=0; i < organization.departments_count; i++) {
    CreateDepartment(organization.departments[i]);
  }
}

void PrintOrganizationSummary(const Organization& organization) {
  std::cout << "Name" << "\t| " << "Employees"	\
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
