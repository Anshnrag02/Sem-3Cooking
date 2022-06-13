//sieve of eratosthanos implemented in this code

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
// int n , m;
map<int, vector<int>>adj;
vector<bool>vis(10000,false);
vector<bool>vis2(10000,false);
vector<bool> sieve(10000,1);
vector<int>v;

void Sieve(){
    int n =9999;
    int i;
    for(i=2 ; i*i<=n ; ++i){
        if(sieve[i]==1){
            // cout<<i<<" ";
            for(int p = i*i ; p <=n ; p+=i){
                sieve[p]=0;
            }
        }
    }


    for(i=1000 ; i<10000 ; ++i){
        if(sieve[i]==1){
            // cout<<i;
            v.pb(i);
        }
    }

}

bool cmp (int am , int bm){
    string a = to_string(am);
    string b = to_string(bm);
    int x=0;
    for(int i = 0 ; i < 4 ; ++i){
        if(a[i]!=b[i]) x++;
    }
    return (x==1);
}




int main(){

    Sieve();
    int n = v.size();
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(cmp(v[i],v[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // for(int i = 0 ; i < n ; ++i){
    //     for(auto x:adj[i]){
    //         cout<<v[x]<<" ";;
    //     }
    //     cout<<endl;
    // }

    int u,k; cin>>u>>k;
    for(int i = 0 ; i < n ; ++i){
        if(v[i]==u){
            u=i; break;
        }
    }
    for(int i = 0 ; i < n ; ++i){
        if(v[i]==k){
            k=i; break;
        }
    }
    queue<pair<int,int>>q;
    q.push({u,0});
    vis[u]=1;
    
    int moves=0;
    while(!q.empty()){
        pair<int,int> a=q.front();
        q.pop();
        if(a.first==k){
            cout<<a.second;return 0;
        }
        for(auto x: adj[a.first]){
            if(!vis[x]){
                vis[x]=1;
                q.push({x,a.second+1});
            }
        }
    }    
    cout<<-1;   
}