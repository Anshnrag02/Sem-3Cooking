// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long noOfWays(int m , int n , int x) {
        
        vector<vector<long long int>>dp(n+1,vector<long long int>(x+1,0));
        // code here
        for(long long j = 1; j<=x and j<=m ;j++){
            dp[1][j]=1;
        }
        
        for(long long i = 2 ; i<=n ; ++i){
            for(long long j = 1; j<=x; ++j){
                for(long long k = 1 ; k<=m and k<j ;++k){
                    dp[i][j]+=dp[i-1][j-k];
                }
            }
        }
        return dp[n][x];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}  // } Driver Code Ends