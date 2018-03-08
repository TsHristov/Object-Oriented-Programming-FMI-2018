#include <iostream>
#include "Organization.h"

int main() {
  Organization organization;

  CreateOrganization(organization);

  PrintOrganizationSummary(organization);

  DestroyOrganization(organization);

  return 0;
}
