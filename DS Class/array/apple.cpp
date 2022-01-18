// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define int long long int

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int  v[], int n)  { 
	    // Your code goes here
	    int sum=0; 
        for(int i = 0 ; i < n ; i++){
            sum+=v[i];
        }
        int ans = sum%1000000007;
        for(int i = 0 ; i < (1<<n) ; ++i){
            int temp = 0;
            for(int j = 0 ; j<n ; j++){
                
                if(1<<j & i){ 
                    temp+=v[j];
                }
            }
            ans = min(ans,abs(sum-temp-temp));
        }
        return (ans)%1000000007;
	} 
};


// { Driver Code Starts.
int32_t main() 
{
    int t=1;
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