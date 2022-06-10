#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

int n,m;
map<int,vector<int>>adj;
int ans=0;
void dfs(int i , int pr,vector<int>&dp){
    // cout<<i<<pr<<endl;
    vector<int>f;
    for(auto x:adj[i]){
        if(x!=pr)
        {
            f.pb(x);
        }
    }
    if(f.empty())
    {
        dp[i]=1;
        return;
    }
    if(f.size()==1){
        dfs(f[0],i,dp);
        dp[i]=1+dp[f[0]];
        return;
    }
    dfs(f[0],i,dp);
    dfs(f[1],i,dp);
    dp[i]=1+dp[f[0]]+dp[f[1]];
}

int sol(int i, int pr,vector<int>&dp){
    int tmp=0;
    vi f;
    for(auto x:adj[i]){
        if(x!=pr){
            f.pb(x);
        }
    }

    if(f.empty()){
        return 0;
    }

    if(f.size()==1){
        return dp[f[0]]-1;
    }
    return max(dp[f[0]]-1+sol(f[1],i,dp),dp[f[1]]-1+sol(f[0],i,dp));
}


// int sol(int i ,int inc,int pr, vector<vector<int>>&dp){
    
//     if(dp[i][inc]!=-1) return dp[i][inc];
    
//     s.insert(i);
//     if(adj[i].size()==1){
//         return dp[i][inc]=inc;
//     }
//     dp[i][inc]=inc;
//     for(auto x:adj[i]){
//         if(x!=pr)
//             if(inc==0)
//                 dp[i][inc]+=sol(x,1,i,dp);
//             else
//                 dp[i][inc]+=min(sol(x,1,i,dp),sol(x,0,i,dp));
//     }

//     return dp[i][inc];
// }

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        m=n-1;
        int u,v;
        for(int i = 0 ; i <m ; ++i)
        {
            cin>>u>>v;
            // u-- ; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dp(n+1);
        dfs(1,0,dp);
        cout<<sol(1,0,dp)<<endl;
        adj.clear();
    }
}