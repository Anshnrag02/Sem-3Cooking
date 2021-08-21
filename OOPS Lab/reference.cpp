#include<iostream>
#define SUM(a,b) (a+b)
#define DIFF(a,b) (a-b)
#define PROD(a,b) (a*b)
#define DIV(a,b) (a/b)
using namespace std;

int main(){
    float num_1,num_2;
    int n;
    cout<<"Enter the first number: ";
    cin>>num_1;
    cout<<"Enter the second number: ";
    cin>>num_2;
    cout<<"Enter the following for operations:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\nEnter the Choice\n";
    cin>>n;
    switch(n){
        case 1:
            cout<<SUM(num_1, num_2)<<endl;
            break;
        case 2:
            cout<<DIFF(num_1, num_2)<<endl;
            break;
        case 3:
            cout<<PROD(num_1, num_2)<<endl;
            break;
        case 4:
            cout<<DIV(num_1, num_2)<<endl;
            break;    
    }
    return 0;
}