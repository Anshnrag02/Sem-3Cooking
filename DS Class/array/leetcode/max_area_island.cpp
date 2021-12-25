#include<bits/stdc++.h>

class Solution {
public:
    
    int island(vector<vector<int>>& grid,int x, int y){
        if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size()){
            return 0;
        }
        
        if(grid[x][y]==0){
            return 0;
        }
        
        grid[x][y]=0;
        return 1+ island(grid,x+1,y) + island(grid,x-1,y) + island(grid,x,y+1) + island(grid,x,y-1);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int area=0;
        int max_area=0;
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid[i][j]==1){
                    area = island(grid,i,j);
                    max_area = max(area,max_area);
                }
            }
        }
        return max_area;
    }
};