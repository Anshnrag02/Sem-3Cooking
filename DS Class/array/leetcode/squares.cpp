#include<bits/stdc++.h>

class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int minidx = 0;
        int n = a.size();
        for (int i = 0 ; i < n ; ++i){
            if(abs(a[i])<abs(a[minidx])){
                minidx = i;
            }
        }
        vector<int>ans;
        ans.push_back(a[minidx]*a[minidx]);
        
        int i=minidx-1,j=minidx+1;
        while(i>=0 and j<n){
            if(a[i]*a[i]<a[j]*a[j]){
                ans.push_back(a[i]*a[i]);
                --i;
            }
            else{
                ans.push_back(a[j]*a[j]);
                ++j;
            }
        }
        
        while(j<n){
            ans.push_back(a[j]*a[j]);
                ++j;            
        }
        
        while(i>-1){
                ans.push_back(a[i]*a[i]);
                --i;
        }
        return ans;
    }
};