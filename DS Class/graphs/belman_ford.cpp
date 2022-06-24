#include<bits/stdc++.h>
using namespace std;
int n , m, ans= INT_MAX;
map<int, vector<int>>adj;
// vector<bool>vis(10000,false);
// vector<bool>vis2(10000,false);
// map<pair<int,int>,int>wt;
vector<vector<int>>E;
vector<int>s(10000,0);
vector<int>p(10000,-1);
vector<int>d(10000,100000);

void relax(int u , int v, int w){
    if(d[v]>d[u]+w){
        d[v]=d[u]+w;
        p[v]=u;
    }
}

void print_parent(int src, int dst){
    if(src==dst)
        cout<<src<<" ";
    else if(p[dst]==-1){
        cout<<"NO Path from "<<src<<" to "<<dst<<endl;
    }
    else{
        print_parent(src,p[dst]);
        cout<<dst<<" ";
    }
}



int main(){

    cin>>n>>m;
    bool ns=0;
    for(int i = 0 ; i < m ; ++i){
        int u,v,w;
        cin>>u>>v>>w;
        // adj[u].push_back(v);
        E.push_back({u,v,w});
    }
    int s;
    cin>>s;
    d[s]=0;

    for(int i = 0 ; i < n-1 ; i++){
        for(int j=0 ; j < m ; ++j){
            relax(E[j][0],E[j][1],E[j][2]);
        }
    }
    for(int j=0 ; j < m ; ++j){
        if(d[E[j][1]]>d[E[j][0]]+E[j][2]){
            ns=1;
            break;
        }
    }

    if(ns==0){
        for(int i = 0 ; i < n ; ++i){
            cout<<d[i]<<" ";
        }
        cout<<endl;
        
        print_parent(0,4);
    }
}