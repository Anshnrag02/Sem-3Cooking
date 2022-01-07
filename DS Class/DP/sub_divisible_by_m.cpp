// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:

		int DivisibleByM(vector<int>a, int m){
		    // Code here
		    int n = a.size();
		    if(n>m){
		        return true;
		    }
		    
		    vector<bool>dp (m,0);

            for(int i = 0 ; i < n ; ++ i ){
                
                if(dp[0]){
                    break;
                }
        
                vector<int>temp(m);
                // here we created a temp just as to keep the cases found in the previous round safe as dp[j] 
                //might show in reference to a[i] instead of going for the previous cases
                //if (a[i]+t)%m index is true then it will be considered as a correct case for (a[i]+j)%m for t<j  
                for(int j = 0 ; j < m ; ++j ){
        
                    if(dp[j]==true){
                        temp[(a[i]+j)%m]=true;
                    }
        
                }
        
                for( int j = 0 ; j<m ; ++j ){
                    if(temp[j]){
                        dp[j]=true;
                    }
                }
                dp[a[i]%m]=true;
            }
            return dp[0];
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans  = ob.DivisibleByM(nums, m);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends