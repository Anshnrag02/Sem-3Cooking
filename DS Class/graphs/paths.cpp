#include<bits/stdc++.h>
using namespace std;
int n , m, k;
map<int, vector<int>>adj;
vector<bool>vis(10000,false);
vector<bool>vis2(10000,false);

// void dfs(int i){
//     vis[i]=1;
//     for(auto x:adj[i]){
//         if(!vis[x]){
//             dfs(x);
//         }
//     }
// }

int cnt=0;


// void remove_node(int i){
//     cout<<"HERE"<<i<<endl;
//     removed[i]=1;
//     vector<int>t=adj[i];
//     adj[i].clear();
//     for(auto x:t){
//         vector<int>::iterator it = find(adj[x].begin(),adj[x].end(),i);
//         adj[x].erase(it);
//         if(adj[x].size()<k){
//             remove_node(x);
//         }
//     }
// }

void dfs(int s, int d){
    
    vis[s]=1;
    for(auto x:adj[s]){
        if(!vis[x]){
            if(x==d){
                cnt++;
            }
            else
                dfs(x,d);
        }
    }
    vis[s]=0;    
}


int main(){

    cin>>n>>m>>k;
    
    for(int i = 0 ; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    int s,d;
    cin>>s>>d;
    dfs(s,d);
    cout<<cnt;
}