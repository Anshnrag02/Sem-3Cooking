#include<bits/stdc++.h>
using namespace std;

bool pdr(string s , int i ,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        --j;
        ++i;
    }
    return true;
}

int solver(string a, int i, int j, vector<vector<int>>&dp){

    if(i==j){
        return dp[i][j]=0;
    }

    if(pdr(a,i,j)){
        return dp[i][j]=0;
    }

    if (dp[i][j]==-1){
        dp[i][j]=INT_MAX;
        for(int k = i ; k < j ; ++k ){
            dp[i][j]=min(dp[i][j], 1+solver(a,i,k,dp)+solver(a,k+1,j,dp));
        }
    }
    
    return dp[i][j];

}

int main(){
    string s;cin>>s;
    int n=s.length();
    vector<vector<int>>dp(n,vector<int>(n,-1)); 
    cout<<solver(s,0,n-1,dp);

}