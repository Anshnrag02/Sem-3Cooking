#include <bits/stdc++.h>
using namespace std;
int n,p;
unordered_map<int,vector<int>>adj;


int main()
{
    cin >> n>>p;
    for (int i = 0; i < n-1; ++i)
    {
        cout<<"yo";
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans = 1;
    queue<vector<int>>q;
    q.push({1,0,-1});
    while(!q.empty()){
        vector<int>f=q.front();
        q.pop();
        int i = f[0];
        int depth=f[1];
        int pr=f[2];
        if(depth<p){
            ans*=2;
        }
        ans=ans%1000000007;
        for(auto x:adj[i]){
            if(x!=pr){
                q.push({x,depth+1,i});
            }
        }
    }
    cout<<ans;
}
