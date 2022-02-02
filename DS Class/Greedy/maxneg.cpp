#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    vector<int>a(n);
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i];
    }
    priority_queue<int,vector<int>,greater<int>>minheap;
    for(int i = 0 ; i < n ; ++i ){
        minheap.push(a[i]);
    }

    while(k--){
        temp=minheap.top();
        minheap.pop();
        temp*=-1;
        minheap.push(temp);
    }
    int s= 0;
    while(!minheap.empty()){
        s+=minheap.top();
        minheap.pop();
    }
    cout<<s;
}