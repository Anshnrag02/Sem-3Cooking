#include<bits/stdc++.h>
using namespace std;
int a[10001],rem[10001];
vector<bool>solved(10001,0);

int main(){
    int n;
    cin>>n;
    int c0w=0,c1w=0,c2w=0;
    int p0w=0,p1w=0,p2w=0;
    for(int i = 0; i<n ; ++i){
        cin>>a[i];
        if(a[i]%3!=i%3){
            if(i%3==0)  c0w++;
            if(i%3==1)  c1w++;
            if(i%3==2)  c2w++;

            if(a[i]%3==0)  p0w++;
            if(a[i]%3==1)  p1w++;
            if(a[i]%3==2)  p2w++;

        }
    }

    if(p0w!=c0w or p1w!=c1w or p2w!=c2w){
        cout<<-1;
    }
    else{
        int ans=0;
        ans+=2*(min({p0w,p1w,p2w}))+max({p0w,p1w,p2w})-min({p0w,p1w,p2w});
        cout<<ans;
    }
    
}