#include<bits/stdc++.h>
using namespace std;
int n; int a[100000];
int dp[1000001];

vector<int>pf(int n){
    vector<int>a;
    for(int i = 2; i*i<=n ; ++i){
        if(n%i==0){
            a.push_back(i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1) a.push_back(n);
    return a;
}

int main(){
    cin>>n;
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i];
    }

    // for(int i =0 ; i<1000001 ; ++i){
    //     dp[i]=0;
    // }


    for(int i = 0 ; i < n ; ++i ){
        vector<int>prime = pf(a[i]);
        
        int ls=0;
        for(auto x: prime){
            ls=max(ls,dp[x]);
        }

        for(auto x: prime){
            dp[x]=ls+1;
        }
    }
    cout<<*max_element(dp,dp+1000001);
}