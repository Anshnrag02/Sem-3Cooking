#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>a={1,2,3,4,6,9,13,15};
    vector<int>b={2,5,8,11,16};
    int n = a.size(),m=b.size();
    int i = 0,j=0,k=n-1;
    while(i<=k and j<m){
        if(a[i]<b[j]){
            ++i;
        }
        else{
            swap(a[k--],b[j++]);
        }
    }
    sort(a.begin(),a.end());
    for(auto x:a){
        cout<<x<<" ";
    }
    sort(b.begin(),b.end());
    for(auto x:b){
        cout<<x<<" ";
    }

}