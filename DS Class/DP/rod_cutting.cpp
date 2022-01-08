// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //cod
        vector<int>dp(n+1,0);
        dp[1]=price[0];
        for(int i = 2; i<=n ; ++i){
            int temp = 0;
            for(int j = 1; j<=i/2 ; j++){
                temp=max(dp[j]+dp[i-j],temp);
            }
            dp[i]=max(price[i-1],temp);
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends