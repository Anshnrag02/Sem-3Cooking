#include<bits/stdc++.h>
using namespace std;

int n,m;

int main(){

    cin>>n>>m;

    vector<string>a(n);
    for(auto &x:a)
        cin>>x;
    int dp[n+1][m+1][2];
    int ans=0;
    for(int i = 0 ; i < n ; ++i){
        for(int j=0 ; j < m ; ++i){
            if(i==0 and j==0){
                dp[i][j][0]=0;
                dp[i][j][1]=1;
            }
            else if(i==0){
                if(a[i][j]==a[i][j-1]){
                    dp[i][j][0]=dp[i][j-1][1];
                    dp[i][j][1]=dp[i][j-1][0]+1;
                }
                else{
                    dp[i][j][0]=min(dp[i][j-1][1],dp[i][j-1][0]);
                    dp[i][j][1]=1+dp[i][j][0];
                }
            }
            else if(j==0){
                if(a[i][j]==a[i-1][j]){
                    dp[i][j][0]=dp[i-1][j][1];
                    dp[i][j][1]=dp[i-1][j][0]+1;
                }
                else{
                    dp[i][j][0]=min(dp[i-1][j][1],dp[i-1][j][0]);
                    dp[i][j][1]=1+dp[i][j][0];
                }
            }
            else{
                if(a[i][j]==a[i-1][j] and a[i][j]==a[i][j-1]){
                    dp[i][j][0]=dp[i-1][j][1]+dp[i][j-1][1]-dp[i-1][j-1][1];
                    dp[i][j][1]=dp[i-1][j][0]+dp[i][j-1][0]+1-dp[i-1][j-1][0];
                }
                else if(a[i][j]==a[i-1][j]){
                    dp[i][j][0]=dp[i-1][j][1]+
                }
            }
        }
    }


}