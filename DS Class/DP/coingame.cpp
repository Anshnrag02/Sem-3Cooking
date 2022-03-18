#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int n;
int a[100000];

int solve(int i = 0 , int j =n-1)
{
    if(i==j){
        return dp[i][j]=a[i];
    }

    if(i+1==j)
        return dp[i][j]=max(a[i],a[j]);


    if(dp[i][j]==-1){
        dp[i][j]=max(a[i]+min(solve(i+2,j),solve(i+1,j-1)),a[j]+min(solve(i+1,j-1),solve(i,j-2)));
    }
    return dp[i][j];
}

int main(){
    cin>>n;
    for(int i = 0 ; i<n; ++i){
        cin>>a[i];
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j<n ; ++j){
            dp[i][j]=-1;
        }
    }
    cout<<solve();
}