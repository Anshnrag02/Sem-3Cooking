class Solution {
public:
    string a , b;
    int dp[501][501];
    
    
    int solver(int i , int j){
        if(i==0)
            return dp[i][j]=j;
        if(j==0)
            return dp[i][j]=i;
        
        if(dp[i][j]==-1){
            if(a[i-1]==b[j-1])
                dp[i][j]=solver(i-1,j-1);
            else
                dp[i][j]=1+min({solver(i-1,j),solver(i,j-1),solver(i-1,j-1)});
        }
        
        
        return dp[i][j];
    }
    
    int minDistance(string word1, string word2) {
        for(int i = 0 ; i < 501 ; ++i){
            for(int j = 0 ; j < 501 ; ++j){
                dp[i][j]=-1;
            }
        }
        a=word1; b=word2;
        return solver(a.length(),b.length());    
    }
};