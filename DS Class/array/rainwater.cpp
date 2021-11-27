#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,temp;
    cin>>n;
    vector <int> a;
    int left[n]={0},right[n]={0};
    for ( int i = 0 ; i < n ; ++ i ){
        cin>>temp;
        a.push_back(temp);
        if (i>0)
            left[i]=max(left[i-1],a[i-1]);
    }
    for(int i = n-2 ; i>=0 ; i--){
        right[i]=max(right[i+1], a[i+1]);
    }
     int count  = 0 ; 
    for( int i = 0 ; i < n ; ++ i ){
        if(min(left[i],right[i])>a[i]){
            count+=min(left[i],right[i])-a[i];
        }
    }
    cout<<count;
    return 0; 
}