#include <iostream>
using namespace std;

class employee
{
public:
    float baseSalary, houseAll, travelAll;
    employee()
    {
        cout << "Please enter details of employee.\n";
        baseSalary = 0;
        houseAll = 0;
        travelAll = 0;
    }

    employee(float b, float h, float t)
    {
        cout << "Details of employee are: \n";
        baseSalary = b;
        houseAll = h;
        travelAll = t;
        cout << "Base Salary: " << b << endl;
        cout << "House Allowance: " << h << endl;
        cout << "Travelling Allowance: " << t << endl;
    }
};

class faculty : public employee
{
public:
    void input()
    {
        cout << "Base Salary: ";
        cin >> baseSalary;
        cout << "House Allowance: ";
        cin >> houseAll;
        cout << "Travelling Allowance: ";
        cin >> travelAll;
    }
    void salary()
    {
        cout << "Total salary of Faculty: " << baseSalary + travelAll + houseAll;
    }
};

class staff : public employee
{
public:
    void input()
    {
        cout << "Base Salary: ";
        cin >> baseSalary;
        cout << "House Allowance: ";
        cin >> houseAll;
        cout << "Travelling Allowance: ";
        cin >> travelAll;
    }
    void salary()
    {
        cout << "Total salary of Staff: " << baseSalary + travelAll + houseAll;
    }
};

int main()
{
    faculty f1;
    f1.input();
    f1.salary();
    cout << "\n\n";
    faculty f2;
    f2.salary();
    cout << "\n\n";

    staff s;
    s.input();
    s.salary();
    return 0;
}