// unbounded knapsack solution

#include<bits/stdc++.h>
using namespace std;

int n,cap,wt[100000],a[100000];
int dp[100000];

int main(){
    
    cin>>n>>cap;

    for(int i = 0 ; i <n ;++i){
        cin>>a[i];
    }
    for(int i = 0 ; i <n ;++i){
        cin>>wt[i];
    }
    for(int i =0 ; i<=cap ; ++i){
        dp[i]=0;
    }

    for(int i =0 ; i<n ;++i){
        for(int j=cap ; j>=0; --j){
            if(wt[i]<=j){
                dp[j]=max(dp[j],dp[j-wt[i]]+a[i]);
            }
        }
    }
    
    for(int i= 0 ; i<=cap; ++i){
        cout<<dp[i]<<" ";
    }
}