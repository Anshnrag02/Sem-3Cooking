// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // int solver(string s1, string s2, int n , int m, vector<vector<int>>&dp){
    //     if(m==0){
    //         return dp[n][m] = n;
    //     }
    //     if (n==0){
    //         return dp[n][m] = m;
    //     }
        
    //     if(dp[n][m]==-1){
    //         if (s1[n-1]==s2[m-1]){
    //             dp[n][m] = solver (s1,s2,n-1,m-1,dp);
    //         }
    //         else{
    //             dp[n][m] = 1+ min({solver (s1,s2,n-1,m-1,dp),solver (s1,s2,n,m-1,dp),solver (s1,s2,n-1,m,dp)});
    //         }
    //     }
    //     return dp[n][m];
    // }
  
    int editDistance(string s, string t) {
        // Code here
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(s.length()+1, vector<int>(t.length()+1, INT_MAX));
        dp[0][0]=0;
        for(int i = 0 ; i <=n ; ++i){
            for(int j = 0; j<=m ; ++j){
                // if(i==0){
                //     dp[i][j]=j;
                // }
                // else if(j==0){
                //     dp[i][j]=i;
                // }
                {

                    if(i>0){
                        dp[i][j] = min(dp[i-1][j]+1,dp[i][j]); 
                    }
                    if(j>0){
                        dp[i][j] = min(dp[i][j-1]+1,dp[i][j]);
                    }
                    if(i>0 and j>0){
                        dp[i][j] = min(dp[i][j],dp[i-1][j-1]+ (s[i-1]==t[j-1]?0:1));
                    }
                }

            }
        }

        return dp[n][m];


        // return solver(s,t,n,m,dp);
    }
};

// { Driver Code Starts.
int main() {
    int T=1;
    // cin >> T;
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    return 0;
}
  // } Driver Code Ends