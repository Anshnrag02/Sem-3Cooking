class Solution {
public:
    
    int countSquares(vector<vector<int>>& matrix) {
        int n =  matrix.size();
        int m = matrix[0].size();
        int ans=0;
        vector<vector<int>>a(n, vector<int>(m));
        for(int i = 0 ; i < n ; ++i){
            a[i][0]=matrix[i][0];
        }
        for(int i = 0 ; i < m ; ++i){
            a[0][i]=matrix[0][i];
        }
        for(int i = 1 ; i < n ; ++i){
            for(int j = 1 ; j< m; ++j){
                if(matrix[i][j]==1)
                {   
                    a[i][j]=matrix[i][j]+min({a[i-1][j],a[i-1][j-1],a[i][j-1]});
                }
            }
        }
        
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                ans+=a[i][j];
            }
        }
        
        return ans;
        
    }
};