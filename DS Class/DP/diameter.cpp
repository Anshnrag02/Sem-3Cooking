#include<bits/stdc++.h>
using namespace std;

int n,m;
// int dp[10001];
map<int,vector<int>>adj;
int ans=INT_MIN;

int dfs(int i , int pr){
    // cout<<i<<pr<<endl;
    vector<int>sum;
    for(auto x:adj[i]){
        if(x!=pr)
        {
            sum.push_back(dfs(x,i));     
        }
    }
    if(sum.size()==0){
        ans=max(ans,0);
        return 0;
    }
    if(sum.size()==1){
        ans=max({ans,1+sum[0]});
        return 1+sum[0];
    }
        ans = max(ans,2+sum[0]+sum[1]);
        return 1+max(sum[0],sum[1]);
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
    int i = dfs(1,0);
    cout<<ans;
}