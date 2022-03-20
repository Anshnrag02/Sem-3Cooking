#include<bits/stdc++.h>
using namespace std;

 int main(){
 
    int t; cin>>t;
    for(int _ = 0 ; _ < t; ++_){
        string a,b;
        cin>>a>>b;
        int i = 0 , j = 0 ;
        bool flag = 0; 
        int ans = 0;
        if(a.length()>b.length()){
            flag =1;
        }
        else{
            while(i<a.length()){
                
                if(a[i]==b[j])
                {
                    i++;
                    j++;
                }else{
                    ans++;
                    j++;
                }
                
                if(b.length()-j<a.length()-i){
                    flag =1;
                    break;
                }
                
                if(i==a.length()){
                    ans+=b.length()-j;
                }
                
                
            }
        }
        
        cout<<"Case #"<<_+1<<": ";
        if(!flag)
            cout<<ans<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;
    }
 }