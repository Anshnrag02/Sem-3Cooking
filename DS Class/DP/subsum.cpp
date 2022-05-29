//subset sum problem with repetition



#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvb vector<vector<bool>>

int main(){
    int n,sum;
    cin>>n>>sum;
    vi a(n);    
    for(auto &x : a){
        cin>>x;
    }
    vvb dp(2,vector<bool>(sum+1,-1));
    for(int i = 0 ; i <= n ; ++i){
        for(int j = 0 ; j <= sum ; j++){

            if(j==0){
                dp[i%2][j]=true;
            }
            else if(i==0){
                dp[i%2][j]=false;
            }
            else{
                if(j>=a[i-1]){
                    dp[i%2][j]=dp[!(i%2)][j]||dp[!(i%2)][j-a[i-1]]||dp[(i%2)][j-a[i-1]];
                }
                else{
                    dp[i%2][j]=dp[!(i%2)][j];
                }
            }
        }
    }
    cout<<dp[n%2][sum];
    return 0;
}