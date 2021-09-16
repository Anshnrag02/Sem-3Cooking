#include<iostream>
using namespace std;

class Arr{

        int a[1000];
        int n;
        int key;

        int search(){
            for(int i = 0 ; i < n ; ++i){
                if(a[i]==key){
                    return i; 
                }
            }
            return -1;
        }

    public:

        void input(){
            cout<<"Enter number of elements in array :\n";
            cin>>n;
            cout<<"Enter the elements\n";
            for(int i =0; i<n; i++){
                cin>>a[i];
            }
        }
        
        void searchKey(){
            cout<<"enter the element to be searched:\n";
            cin>>key;
            int temp = search();
            switch (temp)
            {
            case -1:
                cout<<"ELEMENT DOES NOT EXIST";
                break;
            
            default:
                cout<<"Element Found on the index:"<<temp;
                break;
            }
        }

};

int main(){
    Arr a1;
    int temp;
    a1.input();
    a1.searchKey();   
}