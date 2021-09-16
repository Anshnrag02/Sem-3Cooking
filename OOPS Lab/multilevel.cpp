#include <iostream>
using namespace std;

class A
{
protected:
    int a1;

public:
    void get_a()
    {
        cout << "Please input value of a: ";
        cin >> a1;
    }
    void display_a()
    {
        cout << "A = " << a1 << endl;
    }
};
class B : public A
{
protected:
    int b1;

public:
    void get_b()
    {
        cout << "Please input value of b: ";
        cin >> b1;
    }
    void display_b()
    {
        cout << "B = " << b1 << endl;
    }
};
class C : public B
{
protected:
    int c1;

public:
    void get_c()
    {
        cout << "Please input value of c: ";
        cin >> c1;
    }
    void display_c()
    {
        cout << "C = " << c1 << endl;
    }
};

int main()
{
    C c;
    c.get_a();
    c.get_b();
    c.get_c();
    c.display_a();
    c.display_b();
    c.display_c();
    return 0;
}