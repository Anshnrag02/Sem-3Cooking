class Solution {
public:
    
    int lcs(vector<int>& a, vector<int>& b, int i ,int j,vector<vector<int>>& dp){
        if(i==0 or j==0)
            return dp[i][j]=0;
        if(dp[i][j]==-1){
            if(a[i-1]==b[j-1])
                dp[i][j]=1+lcs(a,b,i-1,j-1,dp);
            else
                dp[i][j]=max(lcs(a,b,i-1,j,dp),lcs(a,b,i,j-1,dp));
        }
        return dp[i][j];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        
        vector<int>a;
        set<int>s;
        for(auto x:nums){
            // a.push_back(x);
            s.insert(x);
        }
        for(auto x:s){
            a.push_back(x);
        }
        int n = a.size();
        sort(a.begin(),a.end());
        vector<vector<int>>dp(n+1,vector<int>(nums.size()+1,-1));
        return lcs(a,nums,n,nums.size(),dp);        
    }
};