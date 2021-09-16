#include <iostream>
using namespace std;

class Complex
{ 
        int real;
        int imaginary;
    public:
        Complex(int r=0, int i=0)
        { 
            real = r;
            imaginary = i; 
        }
        
        friend Complex Sum(Complex, Complex);

        void display()
        { 
            cout<<real<<" + "<<imaginary<<"i"<< endl; 
        }
        
        ~Complex(){} 
};

Complex Sum(Complex n1, Complex n2)
{ 
    Complex add;
    add.real = n1.real + n2.real;
    add.imaginary = n1.imaginary + n2.imaginary;
    return add;
}

int main()
{ 
    Complex c1(4,12), c2(1,16),csum;
    cout<<"\n1st complex number: ";
    c1.display();
    cout<<"\n2nd complex number: ";
    c2.display();
    csum = Sum(c1,c2);
    cout<<"\nSum of the complex numbers: ";
    csum.display();
    return 0;
}