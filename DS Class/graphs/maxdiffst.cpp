#include<bits/stdc++.h>
using namespace std;
int n , m, ans= INT_MAX;
map<int, vector<int>>adj;
// vector<bool>vis(10000,false);
// vector<bool>vis2(10000,false);
vector<int>wt(10000,0);
vector<pair<int,int>>E;
vector<int>s(10000,0);

void dfs(int i , int pr){
    s[i]=wt[i];
    for(auto x:adj[i]){
        if(x!=pr){
            dfs(x,i);
            s[i]+=s[x];
        }
    }
}

int main(){

    cin>>n;
    m=n-1;
    for(int i = 0 ; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        E.push_back({u,v});
    }
    
    for(int i = 0 ; i < n ; ++i){
        cin>>wt[i];
    }
    dfs(0,-1);
    for(int i = 0 ; i < E.size() ; ++i ){
        int u = E[i].first;
        int v = E[i].second;
        int p=min(s[u],s[v]);
        int q=s[0]-p;
        ans = min(ans, abs(p-q));
    }

    cout<<ans;
}