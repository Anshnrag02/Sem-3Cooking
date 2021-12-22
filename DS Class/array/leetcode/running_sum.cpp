#include<bits/stdc++.h>

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>dp;
        int n = nums.size();
        dp.push_back(nums[0]);
        for(int i = 1; i < n ; ++i){
            dp.push_back(nums[i]+dp[i-1]);
        }
        return dp;
    }
};