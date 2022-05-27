//house robber problem in minimization
//

#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int solve(int a[], int n) {
        //cod
        vector<int>dp(n+1,0);
        dp[1]=a[0];
        dp[2]=a[1];
        dp[3]=a[2];
        for(int i = 4 ; i<=n ; ++i){
            dp[i]=min({dp[i-1],dp[i-2],dp[i-3]})+a[i-1];
        }
        return min(dp[n-1],dp[n-2],dp[n]);
    }
};

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

        cout << ob.solve(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends