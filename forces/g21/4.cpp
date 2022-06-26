#include<bits/stdc++.h>
using namespace std;
int n , m;
map<int, set<int>>adj;
vector<bool>vis(10000,false);
vector<bool>vis2(10000,false);

void dfs(int i){
    vis[i]=1;
    for(auto x:adj[i]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

int main(){

	int t ; cin>>t;
	while(t--){
		int n; 
		cin>>n;
		vector<int>a(n);
		for(int i = 0 ; i < n ; ++i){
			cin>>a[i];
		}

		queue<pair<int,int>>q;
		q.push({0,0});
		vis[0]=1;
		while(!q.empty()){
			int f = q.front().first;
			int s = q.front().second;
			if(f==n-1){
				cout<<s<<endl;break;
			}
			q.pop();

			for(int x: adj[f]){
				if(!vis[x]){
					q.push({x,s+1});
				}
			}

		}
	}
}