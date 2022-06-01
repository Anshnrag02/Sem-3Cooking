#include<bits/stdc++.h>
using namespace std;

int t,x,y,n;
int a[10000][3];
int dp[1001][100][100];

// int solve(int i,int ntr=0, int oxy=0){
//     if(i==n and oxy<x or ntr<y)
//         return INT_MAX;
//     if(dp[i][ntr][oxy]!=-1) return dp[i][ntr][oxy];

//     int ans=INT_MAX;
//     if(oxy<x or ntr<y){
//         ans = solve(i+1,ntr,oxy);
//         int temp = solve(i+1,ntr+a[i][1],oxy+a[i][0]);
//         if(temp!=INT_MAX){
//             temp+=a[i][2];
//         }
//         ans = min(ans,temp);
//     }
//     else{
//         ans=0;
//     }

//     return dp[i][ntr][oxy]=ans;


// }

int main(){
    cin>>t;
    while(t--){
        cin>>x>>y;
        cin>>n;
        for(int i = 0 ; i < n ; ++i){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        int dp[x+1]
    }
}