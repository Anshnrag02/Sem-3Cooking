//Pair Friends or keep them single


//DP approach O(n)

#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
vector<string>ans;
int n;

void f(int lbc,int rbc,string s=""){
    if(s.length()==2*n){
        ans.push_back(s);
        return;
    }
    if(lbc<n){
        f(lbc+1,rbc,s+'(');
    }

    if(lbc>rbc){
        f(lbc,rbc+1,s+')');
    }
}

int main(){    
    cin>>n;
    // int lbc=0,rbc=0;
    f(0,0);
    for(auto x:ans){
        cout<<x<<endl;
    }
}