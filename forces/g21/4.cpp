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
		int i = 0; 
		int j = n-1;
		while(i<j){
			if(a[i]==i+1 and a[j]==j+1){
				adj[i].insert(j);
				adj[j].insert(i);
				++i;
				j--;
			}
			else{
				break;
			}
		}
		i = 0; 
		j = n-1;
		while(i<j){
			if(a[i]==j+1 and a[j]==i+1){
				adj[i].insert(j);
				adj[j].insert(i);
				++i;
				j--;
			}
			else{
				break;
			}
		}
		for(int i = 0 ; i<n-1 ;++i){
			adj[i].insert(i+1);
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