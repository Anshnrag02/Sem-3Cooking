#include<iostream>
using namespace std;

float sum(float& num_1,float& num_2){
    return num_1+num_2;
}

float diff(float& num_1,float& num_2){
    return num_1-num_2;
}

float prod(float& num_1,float& num_2){
    return num_1*num_2;
}

float div(float& num_1,float& num_2){
    return num_1/num_2;
}

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
            cout<<sum(num_1, num_2)<<endl;
            break;
        case 2:
            cout<<diff(num_1, num_2)<<endl;
            break;
        case 3:
            cout<<prod(num_1, num_2)<<endl;
            break;
        case 4:
            cout<<div(num_1, num_2)<<endl;
            break;    
    }
    return 0;
}