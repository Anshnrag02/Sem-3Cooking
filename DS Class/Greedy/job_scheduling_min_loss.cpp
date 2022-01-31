#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>a, vector<int>b){
    return a[1]*b[2] > b[1]*a[2];
}

int main(){
    int n; 
    cin>>n;
    vector<vector<int>>v(n,vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin>>v[i][1];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>v[i][2];
        v[i][0]=i+1;
    }
    stable_sort(v.begin(),v.end(),compare);

    for(int i =0 ;i< n ; ++i ){
        cout<<v[i][0]<<" ";
    }

}