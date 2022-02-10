#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i =0 ; i < n ; ++i ){
        cin>>a[i];
    }
    bool flag =0;
    for(int i = n-1 ; i > 0 ; --i){
        if(a[i]>a[i-1]){
            int swapper=i;
            for(int j = i ; j < n ; ++j){
                if(a[j]>a[i-1]){
                    swapper = a[swapper]<a[j] ? swapper : j ;
                }
            }
            swap(a[swapper],a[i-1]);
            sort(a.begin()+i, a.end());
            flag =1 ; 
            break;
        }
    }

    if(!flag){
        reverse(a.begin(),a.end());
    }
    for(int i = 0 ; i < n ; ++i ){
        cout<<a[i]<<" ";
    }

}