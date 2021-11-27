#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,temp;
    cin>>n;
    int mex = INT_MIN;
    int mini = INT_MAX;
    unordered_set<int>u;
    vector <int> a;
    for( int i = 0 ; i < n ; ++i ){
        cin>>temp;
        a.push_back(temp);
        u.insert(temp);
        mex = max(mex,temp);
        mini = min(mini,temp);
    }
    int count=0,max_count=0;
    for(int i = mini ; i <= mex ; i++){
        if(u.find(i)==u.end()){
            count=0;
        }
        else{
            count ++;
        }
        max_count=max(count,max_count);
    }
    cout<<max_count;
}