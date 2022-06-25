#include<bits/stdc++.h>
using namespace std;
int n , m;
map<int, unordered_set<int>>adj;
vector<bool>vis(10000,false);
vector<int>s;

void ts(int i){
    vis[i]=1;
    for(auto x:adj[i]){
        if(!vis[x]){
            ts(x);
        }
    }
    s.push_back(i);
    // cout<<i<<endl;
}

int main(){

    cin>>n>>m;
    
    for(int i = 0 ; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
    }
    
    for(int i=1; i <=n ; ++i){
        if(vis[i]==false)
            ts(i);
    }

    int cnt=0;
    vector<pair<int,int>>pr;
    unordered_set<int>us;
    for(int i = n-1 ; i >=0 ; --i){
        us.insert(s[i]);
        // int f = adj[s[i]].size();
        // int k = n-1-i;
        // cnt+=k-f;
        for(int j = 0 ; j < n ; ++j){
            if(us.find(j)==us.end() and adj[s[i]].find(j)==adj[s[i]].end() and s[i]!=j){
                pr.push_back({s[i],j});
                cnt++;
            }
        }
    }
    for(auto x: pr){
        cout<<x.first<<"-"<<x.second<<endl;
    }
    cout<<cnt;
}