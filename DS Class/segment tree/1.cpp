#include<bits/stdc++.h>
using namespace std;
#define int long long int

int a[200000];
int t[1048576];

void createST(int start , int end, int idx){
    if(start==end){
        t[idx]=a[start];
        return;
    }

    int mid = start + (end-start)/2;
    createST(start,mid,2*idx+1);
    createST(mid+1,end,2*idx+2);
    t[idx]=t[2*idx+1]+t[2*idx+2];

}

int query(int s, int e, int idx, int l, int r){
    if(s>r || e<l){
        return 0;
    }

    if( s>=l and e<=r){
        return t[idx];
    }

    int mid = s + (e-s)/2;
    return query(s,mid,2*idx+1,l,r)+query(1+mid,e,2*idx+2,l,r);
}

signed main(){
    
    int n,t; cin>>n>>t;
    for(int i = 0 ; i < n ; ++i) cin>>a[i];
    createST(0,n-1,0);
    while(t--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,n-1,0,l-1,r-1)<<endl;
    }
}