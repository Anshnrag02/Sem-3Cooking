#include<bits/stdc++.h>
using namespace std;

int n,m;
map<int,vector<int>>adj;
// int ans=INT_MIN;
int ans[100000];

void dfs(int i , int pr, vector<int>&dp){
    // cout<<i<<pr<<endl;
    dp[i]=0;
    int cnt=0;
    vector<int>f;
    for(auto x:adj[i]){
        if(x!=pr)
        {
            cnt++;
            dfs(x,i,dp);     
            f.push_back(x);
        }
    }
    if(cnt==0){
        return;
    }
    if(cnt==1){
        dp[i]=1+dp[f[0]];
        return;
    }
    // sort(adj[i].begin(),adj[i].end());
    dp[i]= 1+max(dp[f[0]],dp[f[1]]);
    return;
}

void f(int i , int pr , int psum, vector<int>&dp){
    vector<int>t;
    for(auto x:adj[i]){
        if(x!=pr){
            t.push_back(x);
        }
    }
    if(t.size()==0){
        ans[i]=max(1+psum,dp[1]);
        return;
    }
    if(t.size()==1){
        ans[i]=max(1+psum,dp[i]);
        f(t[0],i,1+pr,dp);
        return;
    }
    ans[i]=max(1+psum,dp[i]);
    f(t[0],i,1+max(psum,dp[t[1]]),dp);
    f(t[1],i,1+max(psum,dp[t[0]]),dp);
    return;
}

int main(){
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
    vector<int>dp(n+1,0);
    dfs(1,0,dp);
    // for(int i = 1 ; i<=n ; ++i){
    //     cout<<dp[i];
    // }
    // vector<int>ans_up(n+1,0);
    f(1,0,INT_MIN,dp);
    for(int i = 1 ; i<=n ; ++i){
        cout<<ans[i];
    }
}