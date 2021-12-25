#include<bits/stdc++.h>

class Solution {
public:
    int findDuplicate(vector<int>& a) {
        unordered_set<int>s;
        int n  =  a.size();
        for(int i = 0 ; i  < n ; ++ i){
            if(s.find(a[i])!=s.end()){
                return a[i];
            }
            s.insert(a[i]);
        }
        return 0;
    }
};