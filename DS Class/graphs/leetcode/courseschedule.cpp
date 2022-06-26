class Solution {
public:
    
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        vector<unordered_set<int>>adj(n);
        vector<int>incoming(n,0);
        vector<bool>vis(n,0);
        vector<int> ans;
        for(auto x:a){
            adj[x[1]].insert(x[0]);
            incoming[x[0]]++;
        }
        int cnt = 0;
        bool flag = 1;
        while(flag and cnt<n){
            queue<int>q;
            
            for(int i = 0 ; i <n ; ++i){
                if(!vis[i] and incoming[i]==0){
                    q.push(i);
                    cnt++;
                    vis[i]=1;
                }
            }
            
            if(q.size()==0){
                flag = 0;
                break;
            }
            
            
            while(!q.empty()){
                int f = q.front();
                ans.push_back(f);
                for(auto x:adj[f]){
                    incoming[x]--;
                }
                q.pop();
            }
            
        }
        // reverse(ans.begin(),ans.end());
        if(!flag) return {};
        return ans;
    }
};