#include<bits/stdc++.h>
using namespace std;
int n , m;
map<int, vector<pair<int,int>>>adj;
vector<vector<int>>E;
vector<bool>vis(10000,false);
vector<bool>vis2(10000,false);

int main(){

    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int s=0;
        for(int i = 0 ; i < m ; ++i){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            E.push_back({w,u,v});
            s|=w;
        }

        sort

    }
}