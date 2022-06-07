#include<bits/stdc++.h>
using namespace std;

int n,m;

class Solution {
public:
    
    int f(int idx, int sl, vector<vector<int>>&dp,vector<int>&a){
        
        if(idx==n) {
            return INT_MAX;
        }
        if(dp[idx][sl]!=-1) return dp[idx][sl];
        
        if(sl==1){
            int s=INT_MIN;
            for(int i=idx; i<n ; ++i)
                s=max(s,a[i]);
            return dp[idx][sl]=s;
        }
        
        int maxsofar=INT_MIN,ans=INT_MAX;
        
        for(int i=idx; i<n-sl+1;++i){
            maxsofar=max(maxsofar,a[i]);
            ans=min(ans,maxsofar+f(i+1,sl-1,dp,a));
        }
        
        return dp[idx][sl]=ans;
        
    }
    
    int minDifficulty(vector<int>& a, int d) {
        n = a.size();
        if(d>n)
            return -1;
        m = d;
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return f(0,m,dp,a);
    }
};