#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>>a(n);
    bool td=1;
    int k = n*n;
    for(int i = n-1 ; i>=0 ; --i){
        if(td){
            for(int j = 0 ; j < n ; ++j){
                a[j].push_back(k--);
            }
            
        }
        else{
            for(int j = n-1 ; j >= 0 ; --j){
                a[j].push_back(k--);
            }
        }
        td=!td;
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}