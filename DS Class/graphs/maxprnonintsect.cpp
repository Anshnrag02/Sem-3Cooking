#include<bits/stdc++.h>
using namespace std;
int n , m;
map<int, vector<int>>adj;
vector<bool>vis(10000,false);
vector<bool>vis2(10000,false);
int ans = 0;

int dfs(int i , int pr,int lsf=0){
    vector<int>v;
    for(auto x: adj[i]){
        if(x!=pr){
            v.push_back(dfs(x,i,lsf+1));
        }
    }
    int ret=0;
    for(int j = 0 ; j < v.size() ; j++){
        for(int k = 0 ; k < v.size(); ++k){
            if(j!=k){
                ans=max(ans,(lsf+v[j])*v[k]);
            }
        }
        ret=max(ret,v[j]);
    }

    ans=max(ans,ret+lsf);
    
    return ret+1;
}


int main(){

    cin>>n;
    m=n-1;
    for(int i = 0 ; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int a = dfs(0,-1);
    cout<<ans;
}