#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i][1];
    }

    for(int i = 0 ; i < n ; ++i){
        cin>>a[i][0];
    }

    sort(a.begin(),a.end());
    int count = 1;
    int selected = 0;
    for( int i = 1 ; i < n ; ++i ){
        if(a[i][1]>=a[selected][0]){
            count++;
            selected = i ;
        }
    }

    cout<<count<<endl;

}

// {1, 3, 0, 5, 8, 5};
//      finish[] =  {2, 4, 6, 7, 9, 9};