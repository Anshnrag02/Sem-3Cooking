// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    long long int solver(int S[], int m, int n, vector<vector<long long int>>&dp){
        
        if(n==0){
            return dp[m][n]=1;
        }
        
        if(m==0){
            return 0;
        }
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        
        dp[m][n]=solver(S,m-1,n,dp);
        
        if(S[m-1]<=n)
            dp[m][n]+=solver(S,m,n-S[m-1],dp);   
        
        return dp[m][n];
    }
    
    
    long long int count(int S[], int m, int n) {
        vector<vector<long long  int>>dp(m+1, vector<long long int>(n+1,-1));
        return solver(S,m,n,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends