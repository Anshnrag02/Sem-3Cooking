// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

    bool finder(string s, vector<string>& ref){
        for(int i = 0 ; i<ref.size(); ++i){
            if(ref[i].compare(s)==0){
                // cout<<ref[i]<<endl;
                return true;
            }
        }
        return false;
    }


    int solver(string s, int n, vector<string>&b, vector<int>&dp){
        // cout<<n<<endl;
        if(n==0){
            // cout<<"reached";
            return dp[n]=1;
        }
        
        if(dp[n]==-1){
            int temp = 0;
            for(int i = 1; i<=n; ++i){
                if(finder(s.substr(n-i,n),b)){
                    temp+=solver(s.substr(0,n-i),n-i,b,dp);   
                    // cout<<i<<" "<<temp;                 
                }
            }
            if(temp>0){
                dp[n]=1;
            }else{
                dp[n]=0;
            }
        }
        return dp[n];
    }

    int wordBreak(string A, vector<string> &B) {
        //code here
        vector<int>dp(A.length()+1,-1);
        // return solver(A,A.length(),B,dp);
        if(solver(A,A.length(),B,dp)){
            return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends