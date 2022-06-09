#include<bits/stdc++.h>
using namespace std;

int n,m;
map<int,vector<int>>adj;

int sol(int i ,int inc,int pr, vector<vector<int>>&dp){
    
    if(dp[i][inc]!=-1) return dp[i][inc];
    
    s.insert(i);
    if(adj[i].size()==1){
        return dp[i][inc]=inc;
    }
    dp[i][inc]=inc;
    for(auto x:adj[i]){
        if(x!=pr)
            if(inc==0)
                dp[i][inc]+=sol(x,1,i,dp);
            else
                dp[i][inc]+=min(sol(x,1,i,dp),sol(x,0,i,dp));
    }

    return dp[i][inc];
}

int main(){
    cin>>n;
    m=n-1;
    int u,v;
    for(int i = 0 ; i <m ; ++i)
    {
        cin>>u>>v;
        u-- ; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>dp(n,vector<int>(2,-1));
    int a = sol(0,0,-1,dp);
    a = min(a,sol(0,1,-1,dp));
    cout<<a;
}