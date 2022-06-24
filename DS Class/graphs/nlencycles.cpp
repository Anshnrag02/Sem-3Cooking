#include<bits/stdc++.h>
using namespace std;
int n , m, l;
map<int, vector<int>>adj;
vector<bool>vis(10000,false);
vector<bool>vis2(10000,false);
// map<pair<int,int>,int>wt;
// vector<vector<int>>E;
int cnt = 0 ; 

// vector<int>s(10000,0);
// vector<int>p(10000,-1);
// vector<int>d(10000,100000);

// void relax(int u , int v, int w){
//     if(d[v]>d[u]+w){
//         d[v]=d[u]+w;
//         p[v]=u;
//     }
// }

// void print_parent(int src, int dst){
//     if(src==dst)
//         cout<<src<<" ";
//     else if(p[dst]==-1){
//         cout<<"NO Path from "<<src<<" to "<<dst<<endl;
//     }
//     else{
//         print_parent(src,p[dst]);
//         cout<<dst<<" ";
//     }
// }

void dfs(int i , int len){
    vis[i]=1;
    for(auto x:adj[i]){
        
        if(!vis[x] and len<l-1 and vis2[x]==0){
            dfs(x,len+1); 
        }
        else if(vis[x] and len==l-1 and vis2[x]==1){
            cnt++;
        }
    }
    vis[i]=0;
}


int main(){

    cin>>n>>m>>l;
    for(int i = 0 ; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // E.push_back({u,v,w});
    }
    for(int i = 0 ; i < n; ++i){
        vis2[i]=1;
        dfs(i,0);
        // for(int _ = i+1 ; _ < n ; _++) vis[_]=0;
    }

    cout<<cnt/2;
}