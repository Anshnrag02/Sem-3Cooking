#include<bits/stdc++.h> 
using namespace std;  
template<typename a1>  
class solution 
{ 
 public: 
    a1 a;  
    public: 
    void data(){  
        cout<<"\nEnter A : ";  
        cin>>a;  
    }  
    void display(){  
        cout<<"A: "<<a<<endl; 
    }  
    template< typename aa ,typename a4 >  
    
    friend void squ(solution<a4> &object);  
};  

template<typename aa ,typename a1>  

void square(solution<a1> &object) 
{  
    aa res;  
    res = object.a * object.a;  
    cout<<"\nResult: "<< res <<"\n";  
} 

int main(){  
    solution<int> obj;  
    obj.data();  
    obj.display();  
    double value =0;  
    square<int>(obj);  
    return 0;  
} 