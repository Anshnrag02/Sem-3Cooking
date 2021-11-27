#include <bits/stdc++.h>
using namespace std;

int main(){
    int s=10;
    int n=8;
    vector<int> a = {1,19,-1,5,6,8,14,7};
    int result;
    bool flag=false;
    unordered_set<int>finder;
    for(int i = 0 ; i  < n ; i++){
        if(finder.find(s-a[i]) != finder.end())
        {   
            result=(a[i]);
            flag=true;
            break;
        }
        finder.insert(a[i]);
    }
    if(flag)
        cout<<result<<","<<s-result;
}