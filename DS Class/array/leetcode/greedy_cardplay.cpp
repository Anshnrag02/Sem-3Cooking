#include<bits/stdc++.h>

class Solution {
public:
       
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        int ll=k-1;
        int sum=0;
        
        for(int i = 0 ; i<= ll ; i++){
            sum+=(a[i]);
        }
        int max_sum=sum;
        int j = n-1;
        for(int i = ll ; i>=0 ;){
            sum-=a[i--];
            sum+=a[j--];
            max_sum=max(sum,max_sum);
        }
        return max_sum;
    }
};