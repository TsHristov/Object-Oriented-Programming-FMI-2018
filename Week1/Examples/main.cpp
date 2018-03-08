#include <iostream>
#include "Organization.h"

using namespace std;

int main() {
  Organization organization;

  CreateOrganization(organization);

  PrintOrganizationSummary(organization);

  DestroyOrganization(organization);

  return 0;
}
