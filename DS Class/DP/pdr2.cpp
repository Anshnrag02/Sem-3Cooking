#include<bits/stdc++.h>
using namespace std;

int n;
class Solution {
public:

    int f(int idx,vector<vector<bool>>&dp,vector<int>&tab){
        
        if(idx==n){
            return 0;
        }

        if(tab[idx]!=-1) return tab[idx];

        int ans=INT_MAX;
        for(int j = idx ; j < n ; ++j ){
            if(dp[idx][j]){
                ans = min(ans,1+f(j+1,dp,tab));
            }
        }
        return tab[idx]=ans;

    }
    
    int minCut(string s) {
        n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        vector<int>tab(n,-1);
        for(int i = n-1; i>=0; --i){
            for(int j = i ; j<n ; ++j){
                if(i==j){
                    dp[i][j]=1;
                }
                else if(i+1==j){
                    if(s[i]==s[j])
                        dp[i][j]=1;
                }
                else{
                    if(s[i]==s[j] and dp[i+1][j-1]==1){
                        dp[i][j]=1;
                    }
                }
            }
        }
        return f(0,dp,tab)-1;
    }
};

int main(){
    Solution obj;
    cout<<obj.minCut("efe");
}