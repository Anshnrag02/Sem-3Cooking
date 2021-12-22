#include<bits/stdc++.h>

class Solution {
public:
    int pivotIndex(vector<int>& a) {
        vector<int>dpl;
        int n =a.size();
        dpl.push_back(a[0]);
        for(int i = 1 ; i < n ; i ++ ){
            dpl.push_back(dpl[i-1]+a[i]);
        }
        for(int i = 0 ; i< n ; i ++){
            if(dpl[i]==dpl[n-1]-dpl[i]+a[i]){
                return i;
            }
        }
        return -1;
    }
};