#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,k; cin>>n>>k; vector<int>a(n);
    for(int i = 0 ; i < n ; ++i){
        cin>>a[i];
    }
    if(k>=n-1){
        cout<<n<<endl;
    }
    else{
        int smalls=0,maxi=0;
        for( int i = 0 ; i<n ; ++i ){
            if(a[i]>maxi){
                maxi=a[i];

                if(i){
                    smalls=1;
                }

            }
            else
                smalls++;
            if(smalls>=k){
                cout<<maxi;
                break;
            }
        }

    }
}