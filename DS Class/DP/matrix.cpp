// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int ans = 0;
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for(int i = 0 ; i<=n ; ++i){
            for(int j =0 ; j<=m ; j++){
                if(j==0 or i==0){
                    dp[i][j]=0;
                }
                else{
                    int a=0 , b=0, c=0;
                    
                    if(i>0){
                        a=dp[i-1][j];
                    }
                    
                    if(j>0){
                        b=dp[i][j-1];
                    }
                    
                    if(i>0  and j>0){
                        c=dp[i-1][j-1];
                    }
                    
                    if(mat[i-1][j-1]==1){
                        dp[i][j] = 1 + min({a,b,c});
                    }else{
                        dp[i][j]=0;
                    }
                }

                ans=max(dp[i][j],ans);
            }
        }
        // for(int i = 0 ; i<=n; i++){
        //     for(int j =0 ; j<=m ; ++j){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        // cout<<m;

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
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends