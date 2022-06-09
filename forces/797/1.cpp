#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n ; 
        cin>>n;
        int f=n/3;
        f-=2;
        if(n%3==0){
            cout<<2+f<<" "<<3+f<<" "<<1+f<<endl;
        }
        if(n%3==1){
            cout<<2+f<<" "<<4+f<<" "<<1+f<<endl;
        }
        if(n%3==2){
            cout<<3+f<<" "<<4+f<<" "<<1+f<<endl;
        }
    }

}