#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x,k; cin>>n>>k;
    vector<int>a(n);
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(n==0){
        cout<<1;
    }
    else if(n>k and k>0){
        if(a[k-1]==a[k]){
            cout<<-1;
        }
        else{
            cout<<a[k-1];
        }
    }
    else if(k==0){
        if(a[0]!=1){
            cout<<1;
        }
        else{
            cout<<-1;
        }
    }
    else{
        cout<<a[n-1];
    }
    
}