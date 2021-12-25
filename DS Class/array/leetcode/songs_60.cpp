#include<bits/stdc++.h>

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> a(60,0);
        int temp,ans=0;
        for(int i = 0 ; i < time.size() ; i ++ ){
            temp=time[i]%60;
            ans+=a[(60-temp)%60];
            a[temp]++;
        }
        return ans;
    }
};