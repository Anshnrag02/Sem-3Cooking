#include<bits/stdc++.h>
using namespace std;
#define ll long long 


long long int modexp(int n,int m,int p){
    if(m==0){
        return 1;
    }
    n%=p;

    int ans = modexp(n,m/2,p);
    ans=ans*ans;
    ans=ans%p;
    if(m&1)
    ans=ans*(n);
    ans=ans%p;
    return ans;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n,m,p;
        cin>>n>>m>>p;
        cout<<modexp(n,m,p)<<endl;
    }
}