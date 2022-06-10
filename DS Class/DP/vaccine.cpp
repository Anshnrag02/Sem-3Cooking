#include<bits/stdc++.h>

#define int long long int
using namespace std;
int a[1001],b[1001];
int d=0;
int MOD=1e9+7;
int s;
int n,s1=0,s2=0;
    
int f(int idx, int sum, vector<vector<int>>&dp){
    if(idx==n){
        if(sum==0)
            return 1;
        return 0;
    }

    if(dp[idx][s+sum]!=-1) return dp[idx][s+sum];

    int ans = (sum==0);

    ans+=f(idx+1,sum+a[idx],dp);
    ans+=f(idx+1,sum-b[idx],dp);

    ans%=MOD;

    return dp[idx][sum+s]=ans;
}


signed main(){
    cin>>n;
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i];
        s1+=a[i];
    }
    for(int i = 0 ; i <n ;++i){
        cin>>b[i];
        s2+=b[i];
    }

    s=max(s1,s2);
    vector<vector<int>>dp(n+1,vector<int>(2*s+1,-1));
    for(int i=0 ; i < n ; ++i){
        d=(d+f(i+1,a[i],dp)%MOD+f(i+1,-b[i],dp)%MOD)%MOD;
    }
    cout<<d;

}