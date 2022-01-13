// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int  v[], int n)  { 
	    // Your code goes here
	    int sum=0; 
        for(int i = 0 ; i < n ; i++){
            sum+=v[i];
        }
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        dp[0][sum]=true;
    
        for(int i = 1 ; i<=n ; ++i){
            for(int j = 0; j<=sum ; j++){
                dp[i][j]=dp[i-1][j];
                if(j-2*v[i-1]>=0 and dp[i-1][j]){
                    dp[i][j-2*v[i-1]] = 1;
                }
            }
        }
    
        for(int j = 0 ; j<=sum ; j++){
            // cout<<dp[n][j];
            if(dp[n][j]==true){
                return j;
            }
        }
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends