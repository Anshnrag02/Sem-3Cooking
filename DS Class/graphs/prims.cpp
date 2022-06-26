#include<bits/stdc++.h>
using namespace std;
int n , m, ans= INT_MAX;
map<int, vector<int>>adj;
vector<bool>vis(10000,false);
vector<bool>vis2(10000,false);
vector<int>wt(10000,0);
map<pair<int,int>,int>E;
vector<int>d(10000,INT_MAX);
vector<int>p(10000,INT_MAX);


int find_min(){
    int min=INT_MAX, mindx;
    for(int i = 0 ; i < n ; ++i){
        if(!vis[i] and d[i]<min){
            mindx=i;
            min=d[i];
        }
    }
    if(min==INT_MAX)
        return -1;
    else
        return mindx;
}

int main(){

    cin>>n>>m;
    for(int i = 0 ; i < m ; ++i){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        E[{u,v}]=w;
        E[{v,u}]=w;
    }

    p[0]=-1;
    d[0]=0;
    int cnt  = 0; 

    while(cnt<n){
        int k = find_min();
        if(k==-1){
            break;
        }
        cnt++;
        vis[k]=1;
        for(auto x: adj[k]){
            if(!vis[x] and d[x]>E[{x,k}]){
                d[x]=E[{x,k}];
                p[x]=k;
            }
        }
        
    }
    for(int i = 0 ; i < n ; ++i){
        if(p[i]!=-1)
        cout<<i<<" "<<p[i]<<" "<<E[{i,p[i]}]<<endl;
    }
}