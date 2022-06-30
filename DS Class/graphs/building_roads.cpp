#include<bits/stdc++.h>
#define int long long int
using namespace std;
int n , m;
vector<bool>vis(10000000,false);



void dfs(int i,vector<vector<int>>&adj){
    vis[i]=1;
    for(auto x:adj[i]){
        if(!vis[x]){
            dfs(x,adj);
        }
    }
}

signed main(){

    cin>>n>>m;
    vector<vector<int>>adj(n+1);    
    for(int i = 0 ; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>ans;
    for(int i=1; i <=n ; ++i){
        if(vis[i]==false){
            dfs(i,adj);
            ans.push_back(i);    
        }
    }
    
    if(ans.size()>1){
        cout<<ans.size()-1<<endl;
        for(int i = 0 ; i < ans.size()-1; ++i){
            cout<<ans[i]<<" "<<ans[i+1]<<endl;
        }
    }
    else{
        cout<<0<<endl;
    }
}