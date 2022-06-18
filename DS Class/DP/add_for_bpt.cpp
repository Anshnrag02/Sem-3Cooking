#include<bits/stdc++.h>
using namespace std;

int n,m;
map<int,vector<int>>adj;
vector<bool>vis(10000,false);
vector<bool>status(10000,0);

void dfs(int i, bool clr = 0){
    vis[i]=1;
    status[i]=clr;
    for(auto x: adj[i]){
        if(!vis[x]){
            dfs(x,!clr);
        }
    }
}

int main(){
    cin>>n>>m;
    int u,v;
    for(int i = 0 ; i <m ; ++i)
    {
        cin>>u>>v;
        // u-- ; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool f=0;
    for(int i = 0 ; i < n ; ++i){
        if(vis[i]==0){
            dfs(i);
        }
    }
    for(int i = 0 ; i < n ; ++i){
        vis[i]=0;
    }
    for(int i = 0 ; i < n ; ++i){
        vis[i]=1;
        for(auto x:adj[i]){
            if(!vis[x]){
                if(status[i]==status[x]){
                    cout<<"NOT BPT";
                    f=1;
                    break;
                }
            }
        }
    }
    if(!f){
        cout<<"YES BPT";
    }
}