#include<bits/stdc++.h>
using namespace std;

int main(){
    int t = 1;
    cin>>t;
    while(t--){
        int n,p;cin>>n>>p;
        int i = 1;
        int counter = 2*n+p;
        while(counter>0){
            int j = i+1;
            while(j<=n){

                cout<<i<<" "<<j<<'\n';

                counter--;
                if(counter==0)
                    break;
                j++;
            }
            
            i++;
        }
    }
}