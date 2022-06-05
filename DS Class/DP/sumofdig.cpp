#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int a[1001],b[1001];
    for(int i=0 ; i<1001; ++i){
        if(i<10)
            a[i]=i;
        else{
            a[i]=a[i-10]+1;
        }
    }
    for(int i=0 ; i<1001; ++i){
        if(i==0)
            b[i]=a[i];
        else{
            b[i]=a[i]+b[i-1];
        }
    }
    while(1){
        int a,x;
        cin>>a>>x;
        
        if(a==-1 and x==-1) break;


        cout<<f(x)-f(a-1)<<endl;
    
    }
}