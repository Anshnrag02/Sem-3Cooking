#include<bits/stdc++.h>

class Solution {
public:
    bool isSafe(int x, int y , int r , int c , vector<vector<int>>& board){
        if(x>=0 and x<r and y>=0 and y<c){
            if(board[x][y]){
                return true;
            }
        }
        return false;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<int>> refboard=board;
        vector<int>dx={0,1,1,-1,0,-1,1,-1};
        vector<int>dy={1,0,1,0,-1,-1,-1,1};
        for( int i = 0 ; i  < rows ; ++ i ){
            for( int j = 0 ; j < cols ; ++ j ){
                int count1=0;
                for(int k = 0 ; k < 8 ; k ++ ){
                    if(isSafe(i+dx[k],j+dy[k],rows,cols,refboard))
                        count1++;
                }
                if(refboard[i][j] and count1!=2 and count1!=3){
                    board[i][j]=0;
                }
                
                else if(refboard[i][j]==0 and count1==3){
                    board[i][j]=1;
                }
            }
        }
    }
};