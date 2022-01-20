#include<bits/stdc++.h>
using namespace std;

int main(){

    int t=1;
    cin>>t;
    while(t--){
        int s,x,temp;

        cin>>x>>s;
        temp =s;
        int masker = 1<<(int)(log2(x));
        int sum = 0;
        int ans =0;
        while(masker){

            // cout<<(masker&x)<<masker<<x<<endl;

            if((masker&x)==masker){

                sum+=(masker*(temp/masker));
                ans = max(ans,(temp/masker));
                // cout<<masker<<" "<<ans<<"\n";
                temp-=masker*(temp/masker);

            }
            masker = masker>>1;
        }

        // cout<<s<<sum<<temp<<endl;
        if(s == sum)
            cout<<ans<<endl;
        else{
            cout<<-1<<endl;
        }
    }
}