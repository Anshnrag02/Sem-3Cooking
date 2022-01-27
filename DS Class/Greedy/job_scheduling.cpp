#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>a(n, vector<int>(2));
    for(int i = 0 ; i <  n ; ++i){
        cin>>a[i][0];
    }
    for(int i = 0 ; i <  n ; ++i){
        cin>>a[i][1];
    }
    sort(a.begin(),a.end());
    dequeue<int>q;
    for(int i = 0 ; i < n; ++i){
        if(q.size()==0){
            q.push_back(i);
        }else{

            if(q.size()<a[i][0]){
                q.push_back(i);
            }else{
                
            }

        }
    }
}