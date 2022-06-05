#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>a(n);
    // unordered_map<int,bool>is;
    unordered_map<int,int>dp;
    for(auto &x: a){
        cin>>x;
        dp[x]=dp[x-1] + 1;
    }

    int t=-1,start,end;
    
    for(auto x:dp){
        if(t<x.second){
            end=x.first;
            t=x.second;
        }
    }

    cout<<t<<endl;

    start=end-k+1;

    for(int i = 0 ; i < n ; ++i ){
        if(a[i]==start){
            cout<<i+1<<" ";
            start++;
        }
        if(start==end+1){
            break;
        }
    }

}