#include<iostream>
using namespace std;

class Calculator{
        float num_1,num_2;
        int n;
    public:
        Calculator(){
            num_1=0;
            num_2=0;
        }
        
        inline float sum(){
            return num_1+num_2;
        }      
        inline float diff(){
            return num_1-num_2;
        }      
        inline float prod(){
            return num_1*num_2;
        }      
        inline float div(){
            return num_1/num_2;
        }      
    
        inline void input(){
            cout<<"Enter the first number: ";
            cin>>num_1;
            cout<<"Enter the second number: ";
            cin>>num_2;
        }

        inline void displayoptions(){
            cout<<"Enter the following for operations:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\nEnter the Choice\n";
        }

        inline void operation(){
            cin>>n;
            switch(n){
                case 1:
                    cout<<sum()<<endl;
                    break;
                case 2:
                    cout<<diff()<<endl;
                    break;
                case 3:
                    cout<<prod()<<endl;
                    break;
                case 4:
                    cout<<div()<<endl;
                    break;    
            }           
        }
}; 

int main(){
    Calculator c;
    c.input();
    c.displayoptions();
    c.operation();
    return 0; 
}