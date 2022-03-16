#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n; vector<int> a(n),dp(n);
    
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i];
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    for(int i = 0 ; i < n - 1; ++i){
        for(int j = i+1; j<=min(n-1,a[i]+i) ; ++j){
            if(dp[j]==INT_MAX)
                dp[j]=dp[i]+1;
        }
    }
    for(int i = 0 ; i < n ; ++i){
        cout<<dp[i]<<" ";
    }
}