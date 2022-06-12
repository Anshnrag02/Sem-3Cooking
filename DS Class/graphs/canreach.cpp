#include<bits/stdc++.h>
using namespace std;
int n , m;
map<int, vector<int>>adj;
// vector<bool>vis(10000,false);
bool tc[1000][1000];

void reach(int s, int d){

    // cout<<s<<d;
    tc[s][d]=1;
    for(auto x :  adj[d]){
        if(tc[s][x]==false){
            if(s==x){
                tc[s][x]=1;
            }
            else{
                reach(s,x);
            }
        }
    }
}

int main(){

    cin>>n>>m;
    
    for(int i = 0 ; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        if(u!=v)
        adj[u].push_back(v);
    }

    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n; ++j){
            tc[i][j]=0;
        }
    }

    for(int i = 0 ; i < n ; ++i){
        reach(i,i);
    }

    for(int i = 0 ; i < n ; ++i){
        for(int j= 0 ; j < n; ++j){
            cout<<tc[i][j]<<" ";
        }
        cout<<endl;
    }
}