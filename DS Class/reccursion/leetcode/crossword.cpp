#include<bits/stdc++.h>

class Solution {
public:
    
    bool check(vector<vector<char>>& a , string s, int r, int c, int idx,vector<vector<bool>>&visited){
        
        if(idx==s.length()){
            return true;
        }
        
        bool top=false;
        
        if(a[r][c]==s[idx]){
            visited[r][c]=true;
            
            if(r>0 and visited[r-1][c]==false){
                
                top=check(a,s,r-1,c,idx+1,visited);
                
            }
            
            if(top){
                return true;
            }
                        
            if(c>0 and visited[r][c-1]==false){
                top=check(a,s,r,c-1,idx+1,visited);
                
            }
            
            if(top){
                return true;
            }
            
            
            if(r<a.size()-1 and visited[r+1][c]==false){
                top=check(a,s,r+1,c,idx+1,visited);
                
            }
            
            if(top){
                return true;
            }
            
            
            if(c<a[0].size()-1 and visited[r][c+1]==false){
                top=check(a,s,r,c+1,idx+1,visited);
                
            }
            
            if(top){
                return true;
            }
            
            
            if(idx+1==s.length() ){
                return true;
            }
        }
        visited[r][c]=false;
        return false;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0 ; i < rows ; i++ ){
            for(int j =0 ; j < cols ; ++ j ){
                if(board[i][j]==word[0]){
                    vector<bool>v(board[0].size(),0);
                    vector<vector<bool>>visited(board.size(),v);
                    if(check(board,word,i,j,0,visited)==true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};