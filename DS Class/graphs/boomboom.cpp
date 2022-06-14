typedef long long int ll ;
class Solution {
public:
    int dfs(int i,vector<bool>&vis){
        vis[i]=1;
        int ans = 1;
        for(auto x:adj[i]){
            if(!vis[x])
            ans+=dfs(x,vis);
        }
        return ans;
    }
    
    map<int,vector<int>>adj;
    int n;
    int maximumDetonation(vector<vector<int>>& bombs) {
        n = bombs.size();int ans = 0; 
        vector<bool>vis(n,0);
        for(int i = 0 ; i < n ; ++i){
            for(int j = i+1 ; j < n ; ++j){
                if(i!=j){
                    ll x1 = ll(bombs[i][0]), y1 = ll(bombs[i][1]), r1  = ll(bombs[i][2]);
                    ll x2 = ll(bombs[j][0]), y2 = ll(bombs[j][1]), r2  = ll(bombs[j][2]);
                    ll val = pow((x1-x2),2) + pow((y1-y2),2);
                    if(val<=r1*r1){
                        adj[i].push_back(j);
                    }
                    if(val<=r2*r2){
                        adj[j].push_back(i);
                    }
                }
            }
        }
        for(int i = 0 ; i < n ; ++i){
            vector<bool>vis(n,0);
            ans=max(ans,dfs(i,vis));
        }
        return ans;
    }
};