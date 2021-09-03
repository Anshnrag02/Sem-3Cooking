#include <iostream>
using namespace std;
class Employee
{
private:
  string name;
  float salary;
  
public:
  static float salarySum;
  
    //constructor1
    Employee ():
        name{"NULL"}, salary{0.0f}
        {}

    //constructor2
    Employee (const string & name, float salary):
      name{name}, salary{salary}
      {}
    
    void input_data ()
    {
        salarySum -= salary;
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter employee salary: ";
        cin >> salary;
        salarySum += salary;
    }
    
    void display (int num = -1)
    {
        cout << "Employee";
        if (num != -1)
          cout << " " << num;
        cout << ": { Name = \"" << name << "\";  Salary = " << salary << " }" << endl;
    }
    
    //Destructor Call
    ~Employee ()
    {
        salarySum -= salary;
    }
};

float Employee::salarySum = 0.0f;

int main ()
{
  cout << fixed;
  cout.precision (2);
  Employee * employees = new Employee[10];
// INPUT EMPLOYEE DETAILS
  for (int i = 0; i < 10; ++i)
    {
      cout << "Enter data for Employee " << i + 1 << ':'<<endl;
      employees[i].input_data ();
    }
  // DISPLAY EMPLOYEE DETAILS
  cout << "Displaying Employee Details: " << endl << endl;
  for (int i = 0; i < 10; ++i)
    {
      employees[i].display (i + 1);
    }
  // DISPLAY SUM OF SALARIES
  cout << "Sum of salaries of employees = " << Employee::salarySum << endl;
  delete[]employees;
  return 0;
}
