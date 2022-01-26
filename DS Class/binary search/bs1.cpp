// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    bool isPossible(int mid,int arr[],int N,int d)
    {
        int reqd=1;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            if(sum+arr[i]<=mid)
            {
                sum+=arr[i];
            }
            else
            {
                if(arr[i]>mid)
                return false;
                sum=arr[i];
                reqd++;
            }
        }
        return reqd<=d;
    }
    int leastWeightCapacity(int arr[], int N, int D) {
        int low=1;
        int high=accumulate(arr,arr+N,0);
        int res=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(mid,arr,N,D))
            {
                res=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends