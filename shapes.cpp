#include <iostream>
using namespace std;
class overloading
{
public:
    void shape();
    void shape(float r);
    void shape(int r);
    void shape(int l, int b);
    void shape(float t, int d, int e);
    void shape(long a);
    void shape(float c, long int g);
    void shape(double j);
    void shape(float h, double f);
    void shape(float l, float b);
    void shape(float t, float d, float e);
};
void overloading::shape()
{
    cout<<"NO VALUE ENTERED\n";
}
void overloading::shape(float r)
{
    cout << "\nRadius of the Circle : " << r << endl;
    cout << "Area of Circle : " << 3.14 * r * r;
}
void overloading::shape(int r)
{
    cout << "\nRadius of the Circle : " << r << endl;
    cout << "Area of Circle : " << 3.14 * r * r;
}
void overloading::shape(int l, int b)
{
    cout << "\nLength of Rectangle  : " << l;
    cout << "\nBreadth of Rectangle : " << b << endl;
    cout << "Area of Rectangle : " << l * b;
}
void overloading::shape(float l, float b)
{
    cout << "\nLength of Rectangle  : " << l;
    cout << "\nBreadth of Rectangle : " << b << endl;
    cout << "Area of Rectangle : " << l * b;
}

void overloading::shape(float t, float d, float e)
{
    cout << "\nSide 1 of Triangle : " << t;
    cout << "\nSide 2 of Triangle : " << d;
    cout << "\nSide 3 of Triangle : " << e << endl;
    cout << "Area of triangle : " << t * d * e;
}


void overloading::shape(float t, int d, int e)
{
    cout << "\nSide 1 of Triangle : " << t;
    cout << "\nSide 2 of Triangle : " << d;
    cout << "\nSide 3 of Triangle : " << e << endl;
    cout << "Area of triangle : " << t * d * e;
}
void overloading::shape(long a)
{
    cout << "\nSide of Square : " << a << endl;
    cout << "Area of square : " << a * a;
}
void overloading::shape(float c, long int g)
{
    cout << "\nRadius of Cone : " << c;
    cout << "\nHeight of Cone : " << g << endl;
    cout << "Volume of Cone : " << (1 / 3) * 3.14 * c * c * g;
}
void overloading::shape(double j)
{
    cout << "\nRadius of Sphere : " << j << endl;
    cout << "Volume of Sphere : " << (4 / 3) * 3.14 * j * j * j;
}
void overloading::shape(float h, double f)
{
    cout << "\nRadius of Cylinder : " << f;
    cout << "\nHeight of Cylinder : " << h;
    cout << "\nVolume of Cylinder : " << 3.14 * f * f * h;
}
int main()
{
    float r, d, e, l, b;
    float t, c, h;
    long a;
    int ch=1;
    double j, f;
    long int g;
    overloading obj;
    cout << "Following Program shows concepts of FUNCTION OVERLOADING";
    cout << "\n Area of Different Shapers";
    cout << "\n\n1. Area of Circle ";
    cout << "\n2. Area of Rectangle";
    cout << "\n3. Area of Triangle";
    cout << "\n4. Area of Square";
    cout << "\n5. Volume of Cone";
    cout << "\n6. Volume of Sphere";
    cout << "\n7. Volume of Cylinder" << endl;
    while(ch>0 and ch<7){    
        cout << "\nEnter your choice (Press 0 to exit) : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter Radius of Circle : ";
            cin >> r;
            obj.shape(r);
            break;
        case 2:
            cout << "\nEnter Length of Rectangle : ";
            cin >> l;
            cout << "\nEnter Breadth of Rectangle : ";
            cin >> b;
            obj.shape(l, b);

            break;
        case 3:
            cout << "\nEnter Side 1 of Triangle : ";
            cin >> d;
            cout << "\nEnter Side 1 of Triangle : ";
            cin >> e;
            obj.shape(0.5, d, e);
            break;
        case 4:
            cout << "\nEnter Side of A Square : ";
            cin >> a;
            obj.shape(a);
            break;
        case 5:
            cout << "\nEnter Radius of Cone : ";
            cin >> c;
            cout << "\nEnter Height of Cone : ";
            cin >> g;
            obj.shape(c, g);
            break;
        case 6:
            cout << "\nEnter Radius of Sphere : ";
            cin >> b;
            obj.shape(b);
            break;
        case 7:
            cout << "\nEnter Radius of Cylinder : ";
            cin >> f;
            cout << "\nEnter Height of Cylinder : ";
            cin >> h;
            obj.shape(h, f);
            break;
        default:
            obj.shape();
        }
    }
    return 0;
}