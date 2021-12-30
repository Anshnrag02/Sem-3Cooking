#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,mini=1;
    cin>>n;
    int m2=0,m3=0,m5=0;
    vector<int>ans={1};
    for( int i=1 ; i < n ; ++i   ){
        int mini = min(2*(ans[m2]),min(3*(ans[m3]),5*(ans[m5])));
        if(mini == 2*(ans[m2])){
            m2++;
        }
        if(mini == 3*(ans[m3])){
            m3++;
        }
        if(mini == 5*(ans[m5])){
            m5++;
        }
        ans.push_back(mini);
    }
    cout<<ans[n-1];
}