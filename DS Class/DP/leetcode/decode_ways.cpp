#include<bits/stdc++.h>

class Solution {
    public:
    int numDecodings(string s) {
        vector<int>dp(s.length()+1,0);
        
        dp[s.length()]=1;
    
        if(s.length()==0)
            return 0;
        
        if(s[0]=='0'){
            return 0;
        }
        
        for( int i = s.length()-1 ; i>=0 ; --i ){
            if(s[i]=='0'){
                dp[i]=0;
            }
            else{
                
                dp[i]+=dp[i+1];
                if(i<s.length()-1 and (s[i]=='1' or(s[i]=='2' and s[i+1]<='6'))){
                    dp[i]+=dp[i+2];
                }
                
            }
        }
        return dp[0];
    }
};