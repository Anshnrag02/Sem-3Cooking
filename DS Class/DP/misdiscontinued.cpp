// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int  v[], int n)  { 
	    // Your code goes here
        vector<int>dp(n,0);
        if(n>=1){
            dp[0]=v[0];
        }
        if(n>=2){
            dp[1]=v[0]+v[1];
        }
        if(n>=3){
            dp[2] = max({dp[1],v[0]+v[2],v[1]+v[2]});
        }

        for ( int i = 3; i < n ; ++i){
            dp[i] =  max({dp[i-1], dp[i-2]+v[i], dp[i-3]+v[i]+v[i-1]});
        }
        return dp[n-1];
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