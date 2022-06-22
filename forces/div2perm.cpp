#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t; 
    while(t--){
        int n ; cin>>n;
        vector<bool>is(n+1,false);
        vector<int>a(n);
        vector<int>b(n);
        for(int i = 0 ; i < n ; ++i){
            cin>>a[i];
            int temp = a[i];
            while(temp){
                if(temp>=1 and temp<=n and !is[temp]){
                    is[temp]=1;
                    break;
                }
                temp/=2;
            }
        }
        bool flag=0;
        for(int i = 1 ; i <= n ; ++i){
            if(!is[i]){
                flag=1;
                break;
            }
        }
        if(!flag)
            cout<<"yes\n";
        else{
            cout<<"no\n";
        }
    }
}