#include<bits/stdc++.h>
using namespace std;
int n , m, k;
map<int, vector<int>>adj;
vector<bool>removed(10000,false);
vector<bool>vis2(10000,false);

// void dfs(int i){
//     vis[i]=1;
//     for(auto x:adj[i]){
//         if(!vis[x]){
//             dfs(x);
//         }
//     }
// }


void remove_node(int i){
    cout<<"HERE"<<i<<endl;
    removed[i]=1;
    vector<int>t=adj[i];
    adj[i].clear();
    for(auto x:t){
        vector<int>::iterator it = find(adj[x].begin(),adj[x].end(),i);
        adj[x].erase(it);
        if(adj[x].size()<k){
            remove_node(x);
        }
    }
}

void dfs(int s, int d){
    if(s==d){
        count++;
    }
}


int main(){

    cin>>n>>m>>k;
    
    for(int i = 0 ; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i <n ; ++i){
        if(removed[i]==false and adj[i].size()<k){
            remove_node(i);
        }
    }
    
    for(int i = 0 ; i < n ; ++i ){
        if(!removed[i]){
            cout<<i<<"-> ";
            for(auto x:adj[i]){
                cout<<x<<" "; 
            }
            cout<<endl;
        }
    }
}