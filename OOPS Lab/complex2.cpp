#include <iostream>
using namespace std;

class Complex
{ 
        int real;
        int imaginary;
    public:
        Complex()
        { 
            real = 0;
            imaginary = 0; 
        }
        
        Complex(int r, int i)
        { 
            real = r;
            imaginary = i; 
        }
        
        friend void display(Complex C);
        
        friend class Sum;
};

void display(Complex C)
{ 
    cout << C.real << " + " << C.imaginary <<"i"<< endl; 
}
class Sum
{ 
    public :
        Complex add(Complex C1, Complex C2)
        { 
            Complex C3(0, 0);
            C3.real = C1.real + C2.real;
            C3.imaginary = C1.imaginary + C2.imaginary;
            return C3; 
        }
};

int main()
{ 
    Complex C1(15, 3);
    Complex C2(6, 4);
    Complex C3;
    Sum S;
    C3 = S.add(C1, C2);
    cout << "\nThe first Complex Number is : ";
    display(C1);
    cout << "\nThe Second Complex Number is : ";
    display(C2);
    cout << endl;
    cout << "\nSum of these two Complex Numbers is : ";
    display(C3);
    return 0;
}