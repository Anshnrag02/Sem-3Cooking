#include<bits/stdc++.h>
using namespace std;

int ans(int a[], int n)
{
   
    // vector<int>dp(n+1);
    int b=0; 
    int c=!((a[0]+a[1])%2);
    int sol01=c;
    for(int i = 2; i < n ; ++i ){
        if((a[i]+a[i-1])%2==0){
            int temp=c;
            c=max(c,b+1);
            b=temp;    
        }
        else{
            b=c;
        }
    }
    c=((a[n-1]+a[0])%2==0 and sol01==0)?max(1+b,c):c;
    // for(int i = 0 ; i <= n ; ++i){
    //     cout<<dp[i]<<" ";
    // }
    return c;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; ++i ){
        cin>>a[i];
    }
    cout<<ans(a,n);
}