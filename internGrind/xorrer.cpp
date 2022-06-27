#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
int max_mask;
int dp[100][100],pp[100][100];


int maxf(int idx , int mask){

    if(mask==max_mask or idx>=n){
        return 0;
    }

    if(pp[idx][mask]!=-1) return pp[idx][mask];

    int fmask=mask+(1<<idx);
    int ans=-100000;
    int fd=fmask;
    int c=0;

    while((fd&1)==1){
        fd=fd>>1;
        c++;
    }
    for(int i = c ; i < n ; ++i){
        
        
        if(((fmask>>(i))&1)==0){
            int temp_mask=fmask+(1<<i);
            int k = a[idx]^a[i];
            int cnt = 0;
            int f=temp_mask;
            while(f&1){
                f=f>>1;
                cnt++;
            }
            ans = max(ans,k+maxf(cnt,temp_mask));            
        }
    }
    return pp[idx][mask]=ans;
}



int minf(int idx , int mask){

    if(mask==max_mask or idx>=n){
        return 0;
    }

    if(dp[idx][mask]!=-1) return dp[idx][mask];

    int fmask=mask+(1<<idx);
    int ans=100000;
    int fd=fmask;
    int c=0;

    while((fd&1)==1){
        fd=fd>>1;
        c++;
    }
    for(int i = c ; i < n ; ++i){
        
        
        if(((fmask>>(i))&1)==0){
            int temp_mask=fmask+(1<<i);
            // if(mask==)
            int k = a[idx]^a[i];
            int cnt = 0;
            int f=temp_mask;
            while(f&1){
                f=f>>1;
                cnt++;
            }
            ans = min(ans,k+minf(cnt,temp_mask));
            
        }
    }
    return dp[idx][mask]=ans;
}


int main(){
    cin>>n;
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i];
    }
    max_mask=(1<<(n)) - 1;
    for(int i = 0 ; i <=n; ++i){
        for(int j = 0 ; j<=max_mask ; ++j){
            dp[i][j]=pp[i][j]=-1;
        }
    }
    int ah = minf(0,0);
    int b = maxf(0,0);
    cout<<ah<<b;

}