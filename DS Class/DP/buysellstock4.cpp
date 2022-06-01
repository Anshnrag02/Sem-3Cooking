class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n = a.size();
        if(n<=1)
            return 0;
        int dp[n][k+1];
        for(int i = 0 ; i <= k ; ++i){
            dp[0][i]=0;
        }
        
        for(int i = 0 ; i < n ; ++i){
            dp[i][0]=0;
        }
        
        for(int j = 1 ; j <= k ; j++ ){
            for(int i = 1 ; i<n ; ++i ){
                dp[i][j]=dp[i-1][j];
                for(int f=0 ; f<i ; f++){
                    dp[i][j]=max(dp[i][j],dp[f][j-1]+a[i]-a[f]);
                }
            }
        }
        
        
        return dp[n-1][k];
        
    }
};