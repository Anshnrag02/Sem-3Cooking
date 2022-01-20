#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i = 0 ; i< n ; ++i){
        cin>>a[i];
    }
    vector<int>dp(n);
    dp[0]=a[0];
    dp[1]=a[0]+a[1];
    for(int i = 2 ; i < n ; ++i){
        dp[i]=a[i];
        int temp=0;
        for(int j = 1 ; j<=sqrt(1+i) ; j++){
            if((i+1)%j==0 and i+1!=j){
                temp = max(temp,dp[j-1]);
                if(j!=1){
                    temp = max(temp,dp[((i+1)/j)-1]);
                }
            }
        }
        dp[i]+=temp;
    }
    for(int i = 0 ; i < n ; ++ i){
        cout<<dp[i]<<" ";
    }
}