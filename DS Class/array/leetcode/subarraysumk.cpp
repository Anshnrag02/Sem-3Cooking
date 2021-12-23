#include<bits/stdc++.h>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>lp;
        int n = nums.size();
        unordered_map<int,int>m;
        m[0]++;
        lp.push_back(0);
        int ans=0;
        for(int i = 1 ; i<=n ; i++){
            lp.push_back(lp[i-1]+nums[i-1]);
            if(m[lp[i]-k]!=0){
                ans+=m[lp[i]-k];
            }
            m[lp[i]]++;
        }
        return ans;
    }
};