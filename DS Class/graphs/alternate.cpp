#include<bits/stdc++.h>
using namespace std;

int a[1000];
vector<int>ans;

int n;


void printed(vector<int>ans){
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
}

void travel(int x,int pr ,int steps){
    if(steps==0){
        printed(ans);
        return;}
    for(int i = 0 ; i < n ; ++i){
        if(a[i]>x and i!=pr){
            ans.push_back(a[i]);
            travel(a[i]-x, i,steps-1);
            ans.pop_back();
        }
    }
}

int main(){
    int s ; cin>>n>>s;
    for(int i = 0 ; i < n ; ++i ){
        cin>>a[i];
    }
    for(int i=0 ; i < n; ++i){
        ans.push_back(a[i]);
        travel(a[i],i,s);
        ans.pop_back();
    }
}