// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int solver(int a[], int n , int sum, vector<vector<int>>&dp)
    {
        if (sum<0){
            return 0;
        }
        
        if(sum==0){
            return dp[n][sum]=1;
        }
        
        if(n<=0){
            return dp[n][sum]=0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        dp[n][sum] = solver(a,n-1,sum,dp)+solver(a,n-1,sum-a[n-1],dp);
        
        return dp[n][sum];
        
    }

    bool isSubsetSum(int N, int arr[], int sum){
        // code here
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        return solver(arr, N, sum, dp);
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends