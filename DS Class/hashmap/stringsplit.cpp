#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int n = s.length();
    int breakpoint =-1;
    vector<int>m(26,-1);
    int cnt = 1;
    int maxlen = 0;
    for(int i = 0 ; i < n ; ++i){
        if(m[s[i]-'a']>=0){
            if(m[s[i]-'a']>breakpoint){
                maxlen=max(maxlen,i-1-breakpoint);
                breakpoint=i-1;
                cnt++;
            }
        }
        m[s[i]-'a']=i;
    }
    maxlen=max(maxlen,n-1-breakpoint);
    cout<<cnt<<;
}