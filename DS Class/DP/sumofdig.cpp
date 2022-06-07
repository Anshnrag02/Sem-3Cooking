#include<bits/stdc++.h>
using namespace std;
#define int long long int
string n;
int dp[10][2][73];


int solve(int idx, int last, int sum){
    if(idx==n.size())
        return sum;
    
    if(dp[idx][last][sum]!=-1) return dp[idx][last][sum];

    int till = last? n[idx]-'0' : 9;

    int ans=0;
    for(int i = 0 ; i <= till ; ++i){
        ans+=solve(idx+1,last&&(i==till),sum+i);
    }
    return dp[idx][last][sum]=ans;
}


int f(int x){
    n=to_string(x);
    for(int i=0 ; i < n.length() ; ++i){
        for(int j = 0 ; j<=1 ; ++j){
            for(int k=0; k<=72; ++k){
                dp[i][j][k]=-1;
            }
        }
    }
    return solve(0,1,0);
}

signed main(){
   while(1){
        int a,b;
        cin>>a>>b;
        
        if(a==-1 and b==-1) break;


        cout<<f(b)-f(a-1)<<endl;
    
    }
}