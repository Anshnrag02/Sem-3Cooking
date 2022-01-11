#include<bits/stdc++.h>
using namespace std;


int solver(string a, string b, int n, int m, vector<vector<int>>&dp){
    if(n<0) return 0;
    if(m<0) return 0;

    if(dp[n][m]==-1){
        if(a[n]==b[m]){
            dp[n][m] = 1 + solver(a,b,n-1,m-1,dp);
        }else{
            dp[n][m] = max(solver(a,b,n-1,m,dp),solver(a,b,n,m-1,dp));
        }
    }

    return dp[n][m];

}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>>dp(s1.length(), vector<int>(s2.length(),-1));
    int ans =  solver(s1,s2,s1.length()-1,s2.length()-1,dp);
    cout<<ans;
}