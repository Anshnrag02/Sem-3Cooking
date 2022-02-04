#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int main(){
    int n,m;
    cin>>n>>m;
    vector<string>s(n);
    for(int i = 0 ; i < n ; ++i){
        cin>>s[i];
        for(int j = 0 ; j <m; j++){
            dp[i][j]=-1;
            visited[i][j]=-1;
        }
    }
    
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j <m; j++){
            if(s[i][j]=='0'){
                solve()
            }
        }
    }
}