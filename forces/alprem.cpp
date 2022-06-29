#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    string s ;
    cin>>s;
    vector<int>m(26,0),m2(26,0);
    for(int i = 0 ; i<n ; ++i){
        m[s[i]-'a']++;
        m2[s[i]-'a']++;
    }

    for(int i = 0 ; i<26 and k>0 ; ++i){
        if(k>=m[i]){
            k-=m[i];
            m[i]=0;
        }else{
            m[i]-=k;
            k=0;
        }
    }
    string ans ="";

    for(int i = 0 ; i < n ; ++i){

        if(m2[s[i]-'a']-m[s[i]-'a']==0){
            cout<<s[i];
        }
        else{
            m2[s[i]-'a']--;
        }
    }
}