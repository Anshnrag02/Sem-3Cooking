#include <iostream>
using namespace std;

class employee
{
public:
    employee()
    {
        cout << "Please Enter details of Employee:\n";
    }
};

class salary
{
public:
    float baseSalary, ta, ha, bonus;
    salary()
    {
        bonus = 3000;
    }
    void TotalSalary()
    {
        cout << "Total Salary of Faculty (including bonus): " << baseSalary + ta + ha + bonus;
    }
};

class faculty : public employee, public salary
{
public:
    void input()
    {
        cout << "Base Salary: ";
        cin >> baseSalary;
        cout << "Travel Allowance: ";
        cin >> ta;
        cout << "House Allowance: ";
        cin >> ha;
    }
};

int main()
{
    faculty f;
    f.input();
    f.TotalSalary();
    return 0;
}