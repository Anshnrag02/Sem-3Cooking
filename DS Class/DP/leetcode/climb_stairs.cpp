#include<bits/stdc++.h>

class Solution {
    
public:
    int climbStairs(int n) {
        vector<int>dp={1,2};
        if(n<=2){
            return dp[n-1];
        }
        for(int i = 2; i <n ; i++){
            dp.push_back(dp[i-1]+dp[i-2]);
        }
        return dp[dp.size()-1];
    }
    
};