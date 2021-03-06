/ { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>>dp(n, vector<int>(m, 0));
        int ans =INT_MIN;
        for(int i = 0 ; i < n ; i++){
            dp[i][0]=M[i][0];
            ans=max(ans,dp[i][0]);
        }
        
        
        for(int j = 1; j < m ; j++){
            for(int i = 0 ; i < n ; i++){
                int temp = 0;
                if(i>0){
                    temp = max(temp,dp[i-1][j-1]);
                }
                if(i<n-1){
                    temp = max(temp,dp[i+1][j-1]);
                }
                temp = max(temp,dp[i][j-1]);
                dp[i][j]+=(temp+M[i][j]);
                
                ans = max(ans,dp[i][j]);
            }
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends