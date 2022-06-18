#include<bits/stdc++.h>
using namespace std;
int n , m;
map<int, vector<int>>adj;
vector<bool>vis(10000,false);
vector<int>status(10000,0);

void dfs(int i){
    vis[i]=1;
    for(auto x:adj[i]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

int main(){

    cin>>n>>m;
    
    for(int i = 0 ; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int queue<int>q;
    q.push(0);
    while(!q.empty()){
        int f=q.top();
        q.pop();
        status[f]=2;
        for(auto x: adj[f]){
            if(status[x]<1){
                q.push(x);
                status[x]=1;
            }
        }
    }
}