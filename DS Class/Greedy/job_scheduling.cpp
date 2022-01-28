#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>a(n, vector<int>(2));
    int m=INT_MIN;
    for(int i = 0 ; i <  n ; ++i){
        cin>>a[i][1];
        m=max(m,a[i][1]);
    }
    for(int i = 0 ; i <  n ; ++i){
        cin>>a[i][0];
    }

    vector<int>occupied(m+1,-1);

    sort(a.begin(),a.end(),greater<>());
    for(int i = 0 ; i < n ; i++){
        for(int j = a[i][1] ; j > 0 ; j-- ){
            if(occupied[j]==-1){
                occupied[j]=i;
                break;
            }
        }
    }

    for(int i = 0 ; i <=m ; ++i){
        if (occupied[i]>=0)
        {
            cout<<a[occupied[i]][0]<<" "<<a[occupied[i]][1]<<endl;
        }
        
    }
        
}