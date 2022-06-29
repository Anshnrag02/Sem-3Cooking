#include<bits/stdc++.h>
using namespace std;
#define int long long int

int a[200000];
int t[1048576]={0};

void createST(int start , int end, int idx){
    if(start==end){
        t[idx]=a[start];
        return;
    }
    int mid = start + (end-start)/2;
    createST(start,mid,2*idx+1);
    createST(mid+1,end,2*idx+2);
}

void upd(int s, int e, int idx, int target, int u){
    if(s==target and e==target){
        t[idx]+=u;
        return;
    }
    int mid = s+(e-s)/2;
    if(target<=mid){
        upd(s,mid,2*idx+1,target,u);
    }
    else{
        upd(mid+1,e,2*idx+2,target,u);
    }

}

int qry(int s, int e, int idx, int target){
    if(s==target and e==target){
        return t[idx];
    }
    int mid = s + (e-s)/2;
    if(target<=mid){
        return qry(s,mid,2*idx+1,target);
    }
    else{
        return qry(mid+1,e,2*idx+2,target);
    }
}

signed main(){
    
    int n,d; cin>>n>>d;
    for(int i = 0 ; i < n ; ++i) cin>>a[i];
    for(int i = 1 ; i < n ; ++i) a[i]=a[i]+a[i-1];
    createST(0,n-1,0);
    for(int i = 0 ; i<50 ; ++i){
        cout<<t[i]<<" ";
    }
    cout<<endl;
    while(d--){
        int f; cin>>f;
        if(f==1){
            int l , r,u ;
            cin>>l>>r>>u;
            upd(0,n-1,0,r-1,u*r);
            for(int i = 0 ; i<50 ; ++i){
                cout<<t[i]<<" ";
            }
            cout<<endl;
            upd(0,n-1,0,l-1,-u*l);
            for(int i = 0 ; i<50 ; ++i){
                cout<<t[i]<<" ";
            }
            cout<<endl;
        }
        else{
            int r;
            cin>>r;
            cout<<qry(0,n-1,0,r-1)-qry(0,n-1,0,r-2)<<endl;
        }
    }
}