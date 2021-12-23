#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<int>current=intervals[0];
        vector<vector<int>>ans;
        for(int i = 1 ; i < n ; ++ i){
            
            if(current[1]>=intervals[i][0]){
                if(current[1]<intervals[i][1])
                    current[1]=intervals[i][1];
            }
            else{
                ans.push_back(current);
                current=intervals[i];
            }
        }
        ans.push_back(current);
        return ans;
    }
};