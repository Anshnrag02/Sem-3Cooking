#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long int
using namespace std;


int solver(vector<string>&a, int n, int m,vector<vector<int>>&dp){
    if(a[n][m]=='*'){
        return 0;
    }

    if(n==0 and m==0){
        return dp[n][m]=1;
    }
    
    if(dp[n][m]==-1){
        int c = 0,b = 0;
        if(n>0)
            c = solver(a,n-1,m,dp)%MOD;
        if(m>0){
            b = solver(a,n,m-1,dp)%MOD;
        }
        dp[n][m]=(c+b)%MOD;
    }
    return dp[n][m]%MOD;
}

int32_t main(){
    int n; cin>>n;
    vector<string>a(n);
    vector<vector<int>>dp(n,vector<int>(n,-1));
    for(int i = 0 ; i<n ; ++i){
        cin>>a[i];
    }
    cout<<solver(a,n-1,n-1,dp);
}