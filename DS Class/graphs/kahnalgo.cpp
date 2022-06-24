#include<bits/stdc++.h>
using namespace std;

int n , m, l;
map<int, vector<int>>adj;
vector<bool>vis(10000,false);
vector<bool>vis2(10000,false);
vector<int>i_deg(10000,0);
// vector<int>o_deg(10000,0);
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

int main(){

    cin>>n>>m;
    for(int i = 0 ; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        i_deg[v]++;
        // E.push_back({u,v,w});
    }
    queue<int>q;
    vector<int>ans;
    int vis_count=0;
    bool f=1;
    while(vis_count<n){
        int temp = vis_count;
        for(int i = 0 ; i < n ; ++i){
            if(!vis[i] and i_deg[i]==0){
                q.push(i);
                vis[i]=1;
                vis_count++;
            }        
        }
        if(vis_count==temp){
            f=0;
            break;
        }
        while(!q.empty()){
            int f = q.front();
            ans.push_back(f);
            q.pop();
            for(auto x: adj[f]){
                i_deg[x]--;
            }
        }
    }
    if(!f)   
        cout<<"NO TS";
    else 
        for(auto x:ans)cout<<x<<" ";
}