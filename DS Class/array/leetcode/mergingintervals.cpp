#include<bits/stdc++.h>

//o(n) extra space

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

//o(1) extra space soln

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int j=0;
        for(int i = 1 ; i < n ; ++ i){
            
            if( intervals[j][1]>=intervals[i][0]){
                if(intervals[j][1]<intervals[i][1])
                    intervals[j][1]=intervals[i][1];
            }
            else{
                j++;
                intervals[j]=intervals[i];
            }
        }
        for(int k = n-1 ; k > j ; k--){
            intervals.pop_back();
        }
        return intervals;
    }
};