#include<bits/stdc++.h>
using namespace std;

int egg(int n , int k ,vector<vector<int>>&dp){

    if(k<=1)
        return dp[n][k]=k;

    if(n==1){
        return dp[n][k]=k;
    }
    
    int res=INT_MIN,mini=INT_MAX;

    if(dp[n][k]==-1){
        for(int i = 1; i<=k; ++i){
            res=max(egg(n-1,i-1,dp),egg(n,k-i,dp));
            mini = min(mini,res);
        }

        dp[n][k]=mini+1;
    }

    return dp[n][k];

}


int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    cout<<egg(n,k,dp);
}