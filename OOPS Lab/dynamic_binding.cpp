#include <iostream>
using namespace std;
using namespace std;
class base
{
public:
    virtual void get() = 0;
    virtual void showdata() = 0;
    virtual void show() = 0;
};
class power : public base
{
    int n, res;

public:
    void get()
    {
        cout << "\nEnter a number : ";
        cin >> n;
    }
    void showdata()
    {
        cout << "The number for which the square and cube have to be found is: " << n << endl;
    }
    int getSquare()
    {
        res = n * n;
        return res;
    }
    int getCube()
    {
        res = n * n * n;
        return res;
    }
    void show()
    {
        cout << "\nSquare of " << n << " is equal to : " << getSquare() << endl;
        cout << "\nCube of " << n << " is equal to : " << getCube() << endl;
    }
};
int main()
{
    base *obj = new power;
    obj->get();
    cout<<endl;
    obj->showdata();
    cout<<endl;
    obj->show();
    return 0;
}