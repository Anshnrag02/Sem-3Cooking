#include<bits/stdc++.h>
using namespace std;
int n , m, ans= INT_MAX;
map<int, vector<int>>adj;
vector<bool>vis(10000,false);
vector<bool>vis2(10000,false);
// vector<int>s(10000,0);

bool isCyclic(int i){
    vis[i]=1;
    vis2[i]=1;
    for(auto x: adj[i]){
        if((!vis[x] and isCyclic(x)) or vis2[x]==1){
            return 1;
        }
    }
    vis2[i]=0;
    return false;
}

int main(){

    cin>>n>>m;
    for(int i = 0 ; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool ans = false;
    for(int i = 0 ;i < n; ++i){
        if(!vis[i] and isCyclic(i)){
            ans=1;
            break;
        }
    }
    cout<<ans;
}