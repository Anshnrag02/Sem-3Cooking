#include<bits/stdc++.h>
using namespace std;

string s;
int n;

bool pdr(int i,int j){
    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;--j;
    }
    return 1;
}

map<int,vector<vector<string>>>dp;


vector<vector<string>> solve(int i = 0 ){
    if(i==s.length()){
        return dp[i]={{}};
    }
    if(dp.count(i))
        return dp[i];

    vector<vector<string>>ans;
    
    for(int j=i; j<n ; ++j){
        if(pdr(i,j)){
            
            string sus = s.substr(i,j-i+1);
            vector<vector<string>>res = solve(j+1);

            for(auto &x: res){
                x.insert(x.begin(),sus);
            }

            if(res.empty()){
                res.push_back({sus});
            }

            for(auto &x: res){
                ans.push_back(x);
            }

        }
    }

    dp[i]=ans;
    return dp[i];
}




int main(){
        
    cin>>s;
    n=s.length();
    auto ans = solve();
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}