#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& a, int target, vector<vector<int>>ans={}, vector<int>current={},int myidx=0) {
        if(target == 0){
            if(current.size()!=0){
                ans.push_back(current);
            }
            return ans;
        }
        for(int i = myidx ; i < a.size() ; ++ i){
            vector<int>c=current;
            if(a[i]<=target){
                c.push_back(a[i]);
                ans = combinationSum(a,target-a[i],ans,c,i);
            }            
        }
        return ans;        
    }
};