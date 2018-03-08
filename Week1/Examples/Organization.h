#ifndef __ORGANIZATION_H__
#define __ORGANIZATION_H__
#include "Department.h"

struct Organization {
  unsigned departments_count;
  Department *departments;
};

void CreateOrganization(Organization&);

void PrintOrganizationSummary(const Organization&);

void DestroyOrganization(Organization&);

#endif
