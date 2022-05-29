class Solution {
public:
    
    bool f(int n , int s, vector<int>&a, vector<vector<int>>&dp){
        if(s==0){
            return dp[n][s]=1;
        }
        if(n==0){
            return dp[n][s]=0;
        }
        
        if(dp[n][s]!=-1) return dp[n][s];
        
        if(s>=a[n-1]){
            return dp[n][s] = f(n-1,s,a,dp)||f(n-1,s-a[n-1],a,dp);    
        }
        return dp[n][s] = f(n-1,s,a,dp);
    }
    
    bool canPartition(vector<int>& nums) {
        if(nums.size()==1){
            return false;
        }
        
        int n = nums.size();
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }      
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return f(n,sum/2,nums,dp);
        
    }
};