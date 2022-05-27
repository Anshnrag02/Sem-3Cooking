#include<bits/stdc++.h>
using namespace std;
vector<string>ans;

void subset(string s, int idx, string t){
    if(idx==s.length()){
        ans.push_back(t);
        return;
    }

    subset(s,idx+1,t);
    subset(s,idx+1,t+s[idx]);

}


int main(){
    string s; cin>>s;
    subset(s,0,"");
    for(auto x:ans){
        cout<<x<<endl;
    }
}