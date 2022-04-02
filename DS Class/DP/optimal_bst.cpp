#include<bits/stdc++.h>

using namespace std;
int dp[10000][10000];
int a[10000];
int n;

int solver(int st, int nd , int m){
    // if(st>nd){
    //     return 0;
    // }
    if(st==nd){
        return a[st]*m;
    }

    if(dp[st][nd]!=-1)
        return dp[st][nd];
    
    dp[st][nd]=INT_MAX;
    for(int i = st ; i<=nd ; ++i){
        dp[st][nd]=min(dp[st][nd],m*a[i]+((i>st?solver(st,i-1,m+1):0)+(i<nd?solver(i+1,nd,m+1):0)));
    }

    return dp[st][nd];

}

int main(){
    
    cin>>n;
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i];
    }
    for(int i = 0 ; i < 10000 ; ++i){
        for(int j = 0 ; j < 10000 ; ++j){
            dp[i][j]=-1;
        }
    }

    int ans = solver(0,n-1,1);
    cout<<ans;
}