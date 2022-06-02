#include<bits/stdc++.h>
using namespace std;
int n,k,p;
int dp[1000][1000];


int f(vector<vector<int>>&a, int idx, int p){
    if(idx==n or p==0){
        return 0;
    }
    
    if(dp[idx][p]!=-1) return dp[idx][p];

    int ans=f(a,idx+1,p);
    for(int i = 0 ; i<min(p,k);++i){
        ans = max(ans,a[idx][i]+f(a,idx+1,p-1-i));
    }
    return dp[idx][p]=ans;
}

int main(){
    cin>>n>>k>>p;
    vector<vector<int>> a(n,vector<int>(k));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j<k ; j++){
            cin>>a[i][j];
            if(j>0){
                a[i][j]+=a[i][j-1];
            }
        }
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j<=p ; j++){
            dp[i][j]=-1;
        }
    }
    cout<<f(a,0,p);

}