#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j<=i ; ++j){
                if(i==j or (j==i-1 and s[j]==s[i])){
                    dp[i][j]=1;
                    count++;
                }
                else{
                    if(s[i]==s[j]){
                        if(dp[i-1][j+1]==true){
                            count++;
                            dp[i][j]=true;
                        }
                    }
                    
                    
                }
            } 
            
        }
        return count;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin>>s;    
        Solution ob;
        cout << ob.countSubstrings(s) << endl;
    }
    return 0;
}  // } Driver Code Ends