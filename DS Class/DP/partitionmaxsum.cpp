int n,k;
class Solution {
public:
    
    int f(int i , vector<int>&a , vector<int>&dp){
        if(i==n){
            return dp[i]=0;
        }
        
        if(dp[i]!=-1) return dp[i];
        int ans=-1,mx=-1;
        for(int j = i ; j < min(n,i+k);++j){
            mx=max(a[j],mx);
            ans=max(mx*(j-i+1)+f(j+1,a,dp),ans);
        }
        return dp[i]=ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& a, int b) {
        k=b;
        n = a.size();
        vector<int>dp(n+1,-1);
        return f(0,a,dp);
    }
};