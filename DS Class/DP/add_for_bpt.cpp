#include<bits/stdc++.h>
using namespace std;

int n,m;
map<int,vector<int>>adj;
vector<bool>vis(10000,false);
vector<bool>status(10000,0);
int cnt0=0, cnt1=0;

void dfs(int i, bool clr = 0){
    vis[i]=1;
    (!clr)?cnt0++:cnt1++;
    status[i]=clr;
    for(auto x: adj[i]){
        if(!vis[x]){
            dfs(x,!clr);
        }
    }
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
    bool f=0;
    for(int i = 0 ; i < n ; ++i){
        if(vis[i]==0){
            dfs(i);
        }
    }
    cout<<cnt1*cnt0-m;
}