#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n,x;
    cin>>n>>x;
    vector<int> pages(n),price(n);
    for(int i = 0 ; i < n ; i++){
        cin>>price[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin>>pages[i];
    }    
    vector<int>dp(x+1,0);
    for(int i = 0 ; i < n ;  i++){
        for(int j = x ; j>0 ; j--){
            if ( j >= price[i] )
                dp[j] = max(dp[j],dp[j-price[i]]+pages[i]);
        }
    }
    cout<<dp[x];
}