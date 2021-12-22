#include<bits/stdc++.h>

class Solution {
public:
       
    void moveZeroes(vector<int>& a) {
        if(a.size()<=1){
            return;
        }
        int num_zero=0;
        int j = 0;
        for(int i = 0 ; i < a.size() ; i ++){
            if(a[i]!=0){
                swap(a[j++],a[i]);
            }
        }
        
        while(j<a.size()){
            a[j++]=0;
        }
    }
};