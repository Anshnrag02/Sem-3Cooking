#include<bits/stdc++.h>
using namespace std;

int n,m;
map<int,vector<int>>adj;

int ans(int i , int pr, bool inc){
    int t = inc?1:0;
    for(auto x:adj[i]){
        if(x!=pr){
            if(inc==1){
                t+=min(ans(x,i,inc),ans(x,i,!inc));
            }
            else{
                t+=ans(x,i,!inc);
            }
        }
    }

    return t;
    
}

pair<int,int> bt(int i, int pr){
    int exc = 0;
    int inc = 1;
    for(auto x: adj[i]){
        if(x!=pr){
            pair<int,int>temp = bt(x,i);
            exc+=temp.second;
            inc+=min(temp.second,temp.first);
        }
    }

    return {exc,inc};
}

void dfs(int i , int pr,vector<vector<int>>&dp){
    
    dp[i][0]=0;
    dp[i][1]=1;
    // cout<<i<<pr<<endl;
    for(auto x:adj[i]){
        if(x!=pr)
        {
            dfs(x,i,dp);
            
            dp[i][0]+=dp[x][1];
            dp[i][1]+=min(dp[x][0],dp[x][1]);
        }
    }
}

// int sol(int i ,int inc,int pr, vector<vector<int>>&dp){
    
//     if(dp[i][inc]!=-1) return dp[i][inc];
    
//     s.insert(i);
//     if(adj[i].size()==1){
//         return dp[i][inc]=inc;
//     }
//     dp[i][inc]=inc;
//     for(auto x:adj[i]){
//         if(x!=pr)
//             if(inc==0)
//                 dp[i][inc]+=sol(x,1,i,dp);
//             else
//                 dp[i][inc]+=min(sol(x,1,i,dp),sol(x,0,i,dp));
//     }

//     return dp[i][inc];
// }

int main(){
    cin>>n;
    m=n-1;
    int u,v;
    for(int i = 0 ; i <m ; ++i)
    {
        cin>>u>>v;
        // u-- ; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>dp(n+1,vector<int>(2));
    dfs(1,0,dp);
    cout<<min(dp[1][0],dp[1][1]);
    pair<int , int>t = bt(0,-1);
    cout<<min(t.first , t.second);
    cout<<min(ans(0,-1,0),ans(0,-1,1));
    // cout<<"yes";
}