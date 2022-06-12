#include<bits/stdc++.h>
using namespace std;
int n , m;
map<int, vector<int>>adj;
vector<bool>vis(10000,false);
vector<bool>vis2(10000,false);

void dfs(int i){
    vis[i]=1;
    for(auto x:adj[i]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

void remove_node(int i){
    vector<int>t=adj[i];
    adj[i].clear();
    for(auto x:t){
        adj[x].erase(adj[x].find(adj[x].begin(),adj[x].end(),i)-adj[x].begin());
        if(adj[x].size()<k){
            remove_node(x);
        }
    }
}

int main(){

    cin>>n>>m;
    
    for(int i = 0 ; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int ans=-1;

    for(int i=0; i <n ; ++i){
        if(vis[i]==false){
            dfs(i);
            ans=i;    
        }
    }
    
    for(int i=0; i<n ;++i){
        vis[i]=0;
    }

    // vis[ans]=1;
    if(ans!=-1)
        dfs(ans);
    
    for(int i = 0 ; i <n ; ++i){
        if(vis[i]==false){
            ans=-1;
            break;
        }
    }
    
    cout<<ans;
}