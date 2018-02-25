// Препроцесорна директива, която указва файла да бъде включен (include-нат) само веднъж.

#pragma once

struct Employee {
  char name[100];
  char department[100];
  unsigned salary;
};

void EnterEmployee();

void PrintEmployee(const Employee&);


