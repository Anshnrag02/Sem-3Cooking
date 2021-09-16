#include <iostream>
using namespace std;
class Bank
{ 
        int principle;
        int roi;
        double interest;
        double time;

        void calc_interest()
        { 
            interest = (principle * roi * time) / 100.00; 
        }

    public:
        Bank()
        {   
            principle = 100000; 
        }
        
        Bank(int x, int y, int years, int months)
        { 
            principle = x;
            roi = y;
            time = years + (months / 12.00); 
        }
        Bank(int x, int y, double years)
        {
            principle = x;
            roi = y;
            time = years; 
        }
        
        Bank(const Bank &B)
        { 
            principle = B.principle;
            roi = B.roi;
            time = B.time; 
        }
        void input()
        { 
            double years, months;
            cout << "\nEnter the Rate of Interest (ROI) : ";
            cin >> roi;
            cout << "\nEnter the number of years : ";
            cin >> years;
            cout << "\nEnter the number of months : ";
            cin >> months;
            time = years + (months / 12);
            calc_interest();
        }

        float showInt(){
            return interest;
        }

        ~Bank() {}
};
int main()
{ Bank B1, B2(4500, 6, 1, 0), B3(7000, 8, 6);
B1.input();
cout << "\nBank case 1 created with default constructor!";
cout << "\nInterest in Bank case 1 is " <<B1.showInt() << " rupees.";
cout << "\n\nBank case 2 created with first parameterizedconstructor !" ;
cout << "\nInterest in Bank case 2 is " <<B2.showInt() << " rupees.";
cout << "\n\nBank case 3 created with second parameterized constructor !" ;
cout << "\nInterest in Bank case 3 is " <<B3.showInt() << " rupees.";
Bank B4 = B1;
cout << "\n\nBank case 4 created with copy constructor !";
cout << "\nInterest in Bank case 4 is " <<B4.showInt() << " rupees.";
return 0;
}
