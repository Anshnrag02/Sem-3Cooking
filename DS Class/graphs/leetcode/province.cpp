class Solution {
public:
    
    void dfs(int i, vector<vector<int>>&adj, vector<bool>&vis){
        vis[i]=1;
        for(int x = 0 ; x < adj.size() ; ++x){
            if(!vis[x] and adj[i][x]==1){
                dfs(x,adj,vis);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& adj) {
        vector<bool>vis(adj.size(),false);
        int ans=0;
        for(int i = 0 ; i < adj.size() ; ++i){
            if(!vis[i]){
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};