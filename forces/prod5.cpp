#include<bits/stdc++.h>
#define pb push_back
#define int long long int
using namespace std;

signed main(){
    int t;cin>>t;
    while(t--){
        int n,x; cin>>n;
        vector<int> zer,pos,neg,a;
        
        for( int i = 0 ; i < n ; ++i ){
            cin>>x;
            if(x>0){
                pos.pb(x);
            }
            else if(x==0){
                zer.pb(x);
            }
            else{
                neg.pb(-x);
            }
            a.push_back(x);
        }
        
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end());
        int p = pos.size();
        int ne = neg.size();
        int ans = -1000000000000000000; 
        
        if(pos.size()>=5){
            ans = max(ans,pos[p-1]*pos[p-2]*pos[p-3]*pos[p-4]*pos[p-5]);
        }

        if(pos.size()>=3 and ne>=2){
            ans = max(ans,pos[p-1]*pos[p-2]*pos[p-3]*neg[ne-1]*neg[ne-2]);
        }

        if(p>=1 and ne>=4){
            ans = max(ans,pos[p-1]*neg[ne-1]*neg[ne-2]*neg[ne-3]*neg[ne-4]);
        }

        if(ne>=5){
            ans = max(ans,-neg[0]*neg[1]*neg[2]*neg[3]*neg[4]);
        }

        if(ne>=3 and p>=2){
            ans = max(ans,-neg[0]*neg[1]*neg[2]*pos[0]*pos[1]);
        }

        if(ne>=1 and p>=4){
            ans = max(ans,-neg[0]*pos[3]*pos[2]*pos[0]*pos[1]);
        }

        if(zer.size()){
            ans = max(0ll,ans);
        }
        cout<<ans<<endl;    
    }
}