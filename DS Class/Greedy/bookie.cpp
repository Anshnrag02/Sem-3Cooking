#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<int>ans;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i][1];
    }
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i][0];
    }
    sort(a.begin(),a.end());
    for(int i = 0 ; i<n ; i++){
        if(i==0){
            ans.push_back(a[i][0]);
        }else{
            bool flag =false;
            for(int j = 0 ; j<ans.size(); j++){
                if(ans[j]<=a[i][1]){
                    flag=true;
                    ans[j]=a[i][0];
                    break;
                }
            }
            if(!flag)
                ans.push_back(a[i][1]);
        }
    }
    if(k>=ans.size());
        cout<<"yes";
    else
        cout<<"No";
}