#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,sum=0; 
    cin>>n;
    vector<int>v(n);
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
        sum+=v[i];
    }
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    dp[0][sum]=true;

    for(int i = 1 ; i<=n ; ++i){
        for(int j = 0; j<=sum ; j++){
            dp[i][j]=dp[i-1][j];
            if(j-2*v[i-1]>=0 and dp[i-1][j]){
                dp[i][j-2*v[i-1]] = 1;
            }
        }
    }

    for(int j = 0 ; j<=sum ; j++){
        // cout<<dp[n][j];
        if(dp[n][j]==true){
            cout<<j;
            break;
        }
    }

    cout<<endl;
    for(int i = 0 ; i <= n ; i++ ){
        for(int j = 0 ; j<= sum ; j++){
            cout<<dp[i][j];
        }
        cout<<endl;
    }

}