#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums, int str=0,vector<int>v={}) {
        if(str == nums.size()){
            return {v};
        }    
        vector<vector<int>>ans,fans,lans;
        vector<int>c=v;
        fans=subsets(nums,str+1,v);
        
        c.push_back(nums[str]);
        lans=subsets(nums,str+1,c);
        for(int i = 0 ; i < fans.size() ; i++){
            ans.push_back(fans[i]);
        }
        for(int i = 0 ; i < lans.size() ; i++){
            ans.push_back(lans[i]);
        }
        return ans;
    }
};