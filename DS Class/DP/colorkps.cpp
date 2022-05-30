#include<bits/stdc++.h>
using namespace std;

int n,m,x;
int w[1000000];

int main(){
    cin>>n>>m>>x;
    for(int i = 0 ; i < n ; ++i) cin>>w[i];
    vector<vector<int>>clr(m+1);
    for(int i = 0 ; i < n ; ++i){
        int t;
        cin>>t;
        clr[t].push_back(w[i]);
    }
    vector<vector<bool>>dp(m+1,vector<bool>(x+1,0));

    for(int i = 0;i<clr[1].size();++i){
        if(clr[1][i]<=x)
            dp[1][clr[1][i]]=1;
            // cout<<clr[1][i];
    }

    for(int i = 2 ; i<=m ; ++i){
        for(int j = 0 ; j<clr[i].size() ; j++){
            for(int k = 0 ; k<=x; ++k){
                if( k-clr[i][j]>=0 and dp[i-1][k-clr[i][j]]==1){
                    dp[i][k]=1;
                }
            }
        }
    }
    int ans=-1;

    for(int i = 0 ; i<=x ;++i){
        if(dp[m][i]==1)
            ans=i;
    }
    cout<<ans;
}