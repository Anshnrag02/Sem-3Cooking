#include<bits/stdc++.h>

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int i = 0, votes = 0 , candidate;
        for( ; i < n ; i ++){
            if(votes==0){
                candidate=arr[i];
                votes=1;
            }
            else{
                if(arr[i]==candidate){
                    votes++;
                }
                else{
                    votes--;
                }
            }
        }
        return candidate;
    }
};