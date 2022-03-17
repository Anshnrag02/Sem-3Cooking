class Solution {
public:
    
    vector<int>a={0,1,0,-1};
    vector<int>b={1,0,-1,0};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        bool flag=0;
        queue<vector<int>>q;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ;  j < m ; ++j){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
                if(grid[i][j]==1){
                    flag =1;
                }
            }
        }
        if(!flag) return 0;
        int ans= 0;
        
        while(!q.empty()){
            auto &arr = q.front();
            int x=arr[0];
            int y=arr[1];
            int z=arr[2];
            q.pop();
            for(int i = 0 ; i < 4 ; ++i){
                int X = x+a[i];
                int Y = y+b[i];
                if(!(X<0 or X>n-1 or Y<0 or Y>m-1))
                {
                    if(grid[X][Y]==1){
                        grid[X][Y]=2;
                        q.push({X,Y,z+1});
                        ans = max(ans, z+1);
                    }
                }
            }
        }
        
        for(auto &x:grid){
            for(auto &y:x){
                if(y==1) return -1;
            }
        }
        
        return ans;
        
    }
};