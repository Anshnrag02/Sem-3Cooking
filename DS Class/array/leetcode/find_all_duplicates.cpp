#include<bits/stdc++.h>

class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        unordered_set<int>s;
        vector<int>ans;
        int n = a.size();
        for(int i = 0 ; i < n ; ++ i){
            if(s.find(a[i])!=s.end()){
                ans.push_back(a[i]);
            }
            s.insert(a[i]);
        }
        return ans;
    }
};