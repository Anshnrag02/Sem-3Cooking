#include<bits/stdc++.h>
using namespace std;

int main (){
    int n,k;
    cin>>n>>k;
    int temp=k;
    vector<int>a(n);
    int high_idx=0,low_idx=0;
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i];
        high_idx=a[i]>a[high_idx]?i:high_idx;
        low_idx=a[i]<a[low_idx]?i:low_idx;
    }
    vector<pair<int,int>>ans;
    while(k>0 and a[high_idx]-a[low_idx]>=2){
        a[high_idx]--;
        a[low_idx]++;
        ans.push_back({high_idx,low_idx});
        for(int i = 0 ; i < n ; ++i){
            high_idx=a[i]>a[high_idx]?i:high_idx;
            low_idx=a[i]<a[low_idx]?i:low_idx;
        }    
        k--;
    }
    cout<<a[high_idx]-a[low_idx]<<" "<<temp-k<<'\n';
    for(int i = 0 ; i < ans.size(); ++i ){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }
}