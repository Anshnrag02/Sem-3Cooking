//sieve of eratosthanos implemented in this code

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int n , m,k;
// map<pair<int,int>, vector<pair<int,int>>>adj;
// vector<bool>vis(10000,false);
// vector<bool>vis2(10000,false);
bool vis[1001][1001]={0};
// int lvl[1001][1001]={0};
int ans=0;

void add_adj(){
    
    queue<vector<int>>q;
    q.push({0,0,1});
    vis[0][0]=1;
    while(!q.empty()){
        
        pair<int,int>p;
        p.first=q.front()[0];
        p.second=q.front()[1];
        
        int lvl=q.front()[2];
        // cout<<p.first<<p.second<<lvl<<q.size()<<endl;
        
        q.pop();
        
        if((p.first==0 and p.second==k) or (p.first==k and p.second==0)){
            ans=lvl;
            // cout<<"YESH";
            return;
        }

        if(!vis[n][p.second]){
            q.push({n,p.second,lvl+1});
            vis[n][p.second]=1;
        }
        
        if(!vis[p.first][m]){
            // cout<<p.first<<m;
            q.push({p.first,m,lvl+1});
            vis[p.first][m]=1;
        }
        
        if(!vis[0][p.second]){
            q.push({0,p.second,lvl+1});
            vis[0][p.second]=1;
        }
        
        if(!vis[p.first][0]){
            q.push({p.first,0,lvl+1});
            vis[p.first][0]=1;
        }

        if(p.second+p.first>=m){
            if(!vis[p.second+p.first-m][m]){
                q.push({p.second+p.first-m,m,lvl+1});
                vis[p.second+p.first-m][m]=1;            
            }
        }
        else{
            if(!vis[0][p.second+p.first]){
                q.push({0,p.second+p.first,lvl+1});
                vis[0][p.second+p.first]=1;            
            }
        }

        if(p.second+p.first>=n){
            if(!vis[n][p.second+p.first-n]){
                q.push({n,p.second+p.first-n,lvl+1});
                vis[n][p.second+p.first-n]=1;            
            }
        }
        else{
            if(!vis[p.second+p.first][0]){
                q.push({p.second+p.first,0,lvl+1});
                vis[p.second+p.first][0]=1;            
            }
        }
        
        if(!vis[0][m]){
            q.push({0,m,lvl+1});
            vis[0][m]=1;
        }

        if(!vis[n][0]){
            q.push({n,0,lvl+1});
            vis[0][m]=1;
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i = 0 ; i <=n ; ++i){
        for(int j = 0 ; j <=m ; ++j){
            vis[i][j]=0;
        }    
    }
    add_adj();
    cout<<ans;   
}