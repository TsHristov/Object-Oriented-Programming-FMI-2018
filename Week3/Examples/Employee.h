#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

class Employee {
 private:
  char *name;
  unsigned salary;
  unsigned id;

 public:
  Employee(const char*, unsigned, unsigned);
  Employee(const Employee&);
  Employee& operator=(const Employee&);
  ~Employee();

 public:
  unsigned get_id()      const { return id; }
  unsigned get_salary()  const { return salary; }
  const char* get_name() const { return name; }
};

#endif
