#include<bits/stdc++.h>
using namespace std;


int n , m , a[10000];
int dp[1000][1000];

int f(int idx, int pl){
    if(idx==n){
        return INT_MAX;
    }
    if(dp[idx][pl]!=-1) return dp[idx][pl];
    if(pl == 1)
    {
        int s=0;
        for(int i=idx ; i<n;++i){
            s+=a[i];
        }
        return dp[idx][pl]=s;
    }

    int sum=INT_MAX,x=0;
    for(int j = idx ; j<n-pl+1 ; ++j){
        x+=a[j];
        sum=min(sum,max(x,f(j+1,pl-1)));
    }

    return dp[idx][pl]=sum;

}


int main(){
    cin>>n>>m;
    // m--;
    for(int i= 0 ; i<n ; ++i){
        cin>>a[i];
        for(int j = 0 ; j<=m;++j){
            dp[i][j]=-1;
        }
    }
    
    cout<<f(0,m);
}