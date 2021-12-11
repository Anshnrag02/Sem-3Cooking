#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<int,int>mp;
        for (int i=0; i <points.size(); i++){
            mp.insert({(points[i][0]*points[i][0]+points[i][1]*points[i][1]),i});
        }
        vector<vector<int>>ans;
        for(auto itr=mp.begin(); itr!=mp.end() && k>0; itr++, k--){
            ans.push_back(points[itr->second]);
        }
        return ans;
    }
};