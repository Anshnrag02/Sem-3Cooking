class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n = a.size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(1001,0));
        for(int i = 0 ; i < n ; ++i){
            
            for(int j=0 ; j<i ; ++j){
                
                int diff = a[i]-a[j]+500;
                
                
                dp[i][diff] = max(1+dp[j][diff],dp[i][diff]);
                ans=max(ans, dp[i][diff]);
            }
        }
        return 1+ans;
    }
};