#include<bits/stdc++.h>
using namespace std;

int mountain(vector <int> a , int n){
    int i;
    for(i = 0 ; i < n-1 ; i++){
        if (a[i]<a[i+1])
            break;
    }
    vector<int>m;
    m.push_back(i);
    for (int j = i + 1 ; j<n-1 ; j++){
        if ( (a[j]<a[j-1] and a[j]<a[j+1])){
            m.push_back(j);
        }
    }
    if(a[n-1]<a[n-2]){
        m.push_back(n-1);
    }
    int ans=-1;
    for(int j = 0 ; j< m.size()-1 ; j++){
        ans=max(ans,m[j+1]-m[j]);
    }
    return ans+1;
}

int main(){
    vector<int> a = {1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1};
    cout<<mountain(a,a.size());

}