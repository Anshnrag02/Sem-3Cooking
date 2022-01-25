#include<bits/stdc++.h>
using namespace std;

int solver(vector<int>&a, int i, int j, vector<vector<int>>&dp){

    if(i==j){
        return 0;
    }

    if (dp[i][j]==-1){
        dp[i][j]=INT_MAX;
        for(int k = i ; k < j ; ++k ){
            dp[i][j] = min(dp[i][j], solver(a,i,k,dp)+solver(a,k+1,j,dp)+a[i-1]*a[k]*a[j]);
        }
    }
    
    return dp[i][j];

}

int main(){
    int n ;
    cin>>n;
    vector<int>v(n);
    for(int i = 0 ; i < n ; ++i){
        cin>>v[i];
    }
    vector<vector<int>>dp(n,vector<int>(n,-1)); 

    cout<<solver(v,1,n-1,dp);

}