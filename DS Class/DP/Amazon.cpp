#include<bits/stdc++.h>
#define int long long int
using namespace std;

signed main(){
    int n,x; cin>>n;
    vector<int>a;
    for(int i = 0 ; i< 3*n; ++i){
        cin>>x;
        a.push_back(x);
    }
    int ans = 0;
    for(int i = 0 ; i < n ; ++i){
        ans+=min({abs(a[3*i]-a[(3*i) + 1]),abs(a[(3*i) + 2]-a[(3*i) + 1]),abs(a[(3*i) + 2]-a[(3*i)])});
    }
    cout<<ans;
}