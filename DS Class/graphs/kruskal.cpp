#include<bits/stdc++.h>
using namespace std;
int n , m;
map<int, vector<int>>adj;
vector<bool>vis(10000,false);
vector<bool>vis2(10000,false);
vector<int>wt(10000,0);
vector<vector<int>>E;
vector<vector<int>>ans;
vector<int>renk(10000,0);
vector<int>p(10000,0);


void link(int x, int y){
    if(renk[x]>renk[y]){
        p[y]=x;
    }
    else{
        p[x]=y;
        if(renk[x]==renk[y]){
            renk[y]++;
        }
    }
}

int find_set(int x){
    if(x!=p[x]){
        p[x]=find_set(p[x]);
    }
    return p[x];
}

void uni(int x , int y){

    link(find_set(x),find_set(y));

}



int main(){

    cin>>n>>m;
    for(int i = 0 ; i < m ; ++i){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        E.push_back({w,u,v});
        p[u]=u;
        p[v]=v;
    }

    sort(E.begin(),E.end());
    unordered_set<int>s;
    for(int i = 0 ; i < m ; ++i){
        if(find_set(E[i][1])!=find_set(E[i][1])){
            ans.push_back(E[i]);
            uni(E[i][1],E[i][2]);
        }
    }
    for(auto x: ans){
        cout<<x[1]<<" "<<x[2]<<" ";
        cout<<endl;
    }

}