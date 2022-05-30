#include<bits/stdc++.h>
using namespace std;

int a[1000000][3];
int dp[3][1000000];
int n;

int mincost(int prev, int idx){
    if(idx==n){
        return 0;
    }

    if(prev!=-1 and dp[prev][idx]!=-1) return dp[prev][idx];

    int ans=INT_MAX;
    for(int i = 0 ; i<3; ++i){
        if(i!=prev){
            ans = min(ans, a[idx][i]+mincost(i,idx+1));
        }
    }
    if(prev==-1){
        return ans;
    }
    else{
        return dp[prev][idx]=ans;
    }
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) {
        // int n;
        cin>>n;
        for(int i = 0 ; i < n ; ++i){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        for(int i = 0 ; i<=n; ++i ){
            dp[0][i]=-1;dp[1][i]=-1;dp[2][i]=-1;
        }
        cout<<mincost(-1,0);
    }
    return 0;
}