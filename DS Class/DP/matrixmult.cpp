#include<bits/stdc++.h>
using namespace std;
int a[1000],dp[1001][1001];

int f(int start,int end){

    if(end==start){
        return dp[start][end]=0;
    }
    if(dp[start][end]==-1){
        dp[start][end]=INT_MAX;
        for(int i = start+1; i<=end;++i){
            dp[start][end]=min(dp[start][end], f(i,end)+f(start,i-1)+a[start-1]*a[end]*a[i-1]);
        }
    }
    return dp[start][end];
}

int main(){
    int n;
    cin>>n;
    for(int i = 0 ; i<n+1 ; ++i){
        cin>>a[i];
    }
    for(int i = 0 ; i<=1000; ++i){
        for(int j = 0 ; j<=1000; ++j){
            dp[i][j]=-1;
        }
    }
    int start = 1, end = n;
    cout<<f(start,end);
      
}
