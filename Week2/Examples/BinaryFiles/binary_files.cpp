#include <iostream>
#include <fstream>
using namespace std;

struct Employee {
  char name[100];
  unsigned salary;
  unsigned employee_id;
};

bool serialize(const Employee& employee, const char* file_name) {
  ofstream output_file(file_name, ios::binary | ios::trunc);

  if(output_file.is_open()) {
    output_file.write((const char*)&employee, sizeof(Employee));
  } else {
    cerr << "Could not open file:" << file_name;
    return false;
  }

  output_file.close();
  return true;
  
}

bool deserialize(Employee& employee, const char* file_name) {
  ifstream input_file(file_name, ios::binary);
  if(input_file.is_open()) {
    input_file.read((char*)&employee, sizeof(Employee));
  } else {
    cerr << "Could not open file:" << file_name;
    return false;
  }

  input_file.close();
  return true;
}

int main(int argc, char *argv[]) {

  const char *file_name = "employees.bin";
  
  Employee employee;
  cin.getline(employee.name, 100);
  cin >> employee.salary;
  cin >> employee.employee_id;
  
  serialize(employee, file_name);

  Employee deserialized_employee;
  deserialize(deserialized_employee, file_name);
  
  cout << "Deserialized employee:\n";
  cout << deserialized_employee.name << "\n";
  cout << deserialized_employee.salary << "\n";
  cout << deserialized_employee.employee_id << "\n";
  
  return 0;
}
