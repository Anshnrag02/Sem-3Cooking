#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        for(int i = 0 ; i <=n ; ++i){
            for(int j = 0 ; j<=m; ++j){
                if(i==0 or j == 0){
                    dp[i][j]=0;
                }
                else{
                    if(nums1[i-1]==nums2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                        ans = max(dp[i][j],ans);
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    int t =1;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>nums1(n),nums2(m);
        for(auto &x:nums1){
            cin>>x;
        }
        for(auto &x:nums2){
            cin>>x;
        }
        Solution s;
        s.findLength(nums1,nums2);
    }
}