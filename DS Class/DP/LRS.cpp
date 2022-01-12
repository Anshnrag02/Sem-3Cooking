#include<bits/stdc++.h>
using namespace std ;
 
int main(){
    string s;
    cin>>s;
    int n = s.length();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j<= n ; j++){
            if (s[i-1]==s[j-1] and j!=i)
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string str="";
    int i = n;
    int j = n;

    while(i>0 and j>0){
        if(dp[i][j]==1+dp[i-1][j-1]){
            str+=s[i-1];
            i--;
            j--;
        }
        else if (dp[i][j]==dp[i-1][j]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(str.begin(),str.end());
    cout<<str;


}