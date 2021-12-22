#include<bits/stdc++.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Profit = 0 ; 
        int max_Profit = INT_MIN;
        for(int i = 0 ; i < prices.size()-1 ; i++){
            Profit+=(prices[i+1]-prices[i]);
            if(Profit>max_Profit){
                max_Profit=Profit;
            }
            if(Profit<0){
                Profit = 0;
            }
        }
        if(max_Profit>0){
            return max_Profit;
        }else{
            return 0;
        }
    }
};