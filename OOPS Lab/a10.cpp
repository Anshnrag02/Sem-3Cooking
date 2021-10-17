#include <iostream>
#include <string>
using namespace std;
class ptr_obj
{
    string name;
    int rollNo;
    static int i;
    public:
    ptr_obj()
    {
        cout << "Object " << i++ << " is called.\n";
    }
    ptr_obj(string name, int rollNo)
    {
        cout << "Object " << i++ << " is called.\n"; 
        this->name = name;
        this->rollNo = rollNo;
    }
    void set_data()
    {
        cout << "Enter roll number: ";
        cin >> this->rollNo;
        cout << "Enter your name: ";
        cin >> this->name;
    }
    void print()
    {
        cout << "Data for object " << i - 1 << "\n";
        cout << "Roll number: " << this->rollNo << "\n";
        cout << "Name of User: " << this->name << "\n\n";
    }
};

int ptr_obj::i = 1;

int main()
{
    ptr_obj a1;
    a1.set_data();
    a1.print();
    ptr_obj a2("Ansh Anurag", 81);
    a2.print();
    ptr_obj a3;
    a3.set_data(); 
    a3.print();
    return 0;
}
