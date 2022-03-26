class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>r,c;
        for(int i = 0 ; i < n ; ++i)
        {
            int cnt = 0;
            for(int j = 0 ; j < m ; ++j){   
                cnt+=grid[i][j];               
            }
            r.push_back(cnt);
        }
        for(int i = 0 ; i < m ; ++i)
        {
            int cnt = 0;
            for(int j = 0 ; j < n ; ++j){   
                cnt+=grid[j][i];               
            }
            c.push_back(cnt);
        }
        int cnt = 0;
        for(int i = 0 ; i < m ; ++i)
        {
            
            for(int j = 0 ; j < n ; ++j){   
                if(grid[j][i]){
                    if(r[j]>1 or c[i]>1)
                        cnt++;
                }               
            }
        }
        return cnt;
    }
};