#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define ifor(a,b) for(int i = 0 ; i< n ; ++i)
using namespace std;

vector<int>nextgreater(vector<int>&a , int n){
    vector<int>ans(n,n);
    stack<int>s;
    for(int i = 0 ; i < n ; ++i){
        while(!s.empty() and a[s.top()]<a[i]){
            ans[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

vector<int>prevgreater(vector<int>&a , int n){
    vector<int>ans(n,-1);
    stack<int>s;
    for(int i = n-1 ; i >=0 ; --i){
        while(!s.empty() and a[s.top()]<a[i]){
            ans[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}



signed main(){
    int t;
    cin>>t;
    while(t--){
        int n cin>>n;
        vector<int>a(n);
        ifor(0,n){
            cin>>a[i];
        }
    }
}