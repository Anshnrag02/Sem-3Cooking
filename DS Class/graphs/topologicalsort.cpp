#include<bits/stdc++.h>
using namespace std;
int n , m;
map<int, vector<int>>adj;
vector<bool>vis(10000,false);
stack<int>s;

void ts(int i){
    vis[i]=1;
    for(auto x:adj[i]){
        if(!vis[x]){
            ts(x);
        }
    }
    s.push(i);
    cout<<i<<endl;
}

int main(){

    cin>>n>>m;
    
    for(int i = 0 ; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    for(int i=1; i <=n ; ++i){
        if(vis[i]==false)
            ts(i);
    }

    

}