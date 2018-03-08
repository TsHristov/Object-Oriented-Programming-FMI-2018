#ifndef __ORGANIZATION_H__
#define __ORGANIZATION_H__
#include "Department.h"

// Дефиниция на структура, която описва огранизация.
// За целите на примера приемаме, че една
// организация се определя от броя департаменти в нея,
// както и от самите департаменти, които съставляват организацията.
struct Organization {
  unsigned departments_count;
  Department *departments;
};

void CreateOrganization(Organization&);

void PrintOrganizationSummary(const Organization&);

void DestroyOrganization(Organization&);

#endif
