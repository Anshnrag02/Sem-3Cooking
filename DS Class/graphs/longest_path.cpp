#include<bits/stdc++.h>
using namespace std;
int n , m;
map<int, vector<int>>adj;
vector<bool>vis(10000,false);
vector<int>d(10000,INT_MIN);
map<pair<int,int>,int>E;
vector<int>s;

void ts(int i){
    vis[i]=1;
    for(auto x:adj[i]){
        if(!vis[x]){
            ts(x);
        }
    }
    s.push_back(i);
}

int main(){

    int src;
    cin>>n>>m>>src;
    d[src]=0;
    for(int i = 0 ; i < m ; ++i){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(v);
        E[{u,v}]=w;
    }
    for(int i = 0 ; i < n ; ++i){
        if(!vis[i]){
            ts(i);
        }
    }


    // for(int i = 0 ; i < n ; ++i){
    //     cout<<s[i];
    // }

    for(int i = n-1; i>=0 ; --i){
        for(auto x: adj[s[i]]){
            if(d[x]<d[s[i]]+E[{s[i],x}]){
                d[x]=d[s[i]]+E[{s[i],x}];
            }
        }
    }
    
    for(int i = 0 ; i < n ; ++i){
        cout<<d[i]<<" ";
    }    
}