#include<bits/stdc++.h>
using namespace std;
#define f0r(i,a,b) for(int i = a ; i<b ; ++i)
int n , m , k;
vector<vector<bool>>vis(1001,vector<bool>(1001,0));
vector<vector<int>>a(1001,vector<int>(1001,0));
vector<vector<int>>mindp(1001,vector<int>(1001,0));

pair<int,int> f(int i=0 , int j=0){
    
    if(i==n-1 and j == m-1){
        return dp[i][j]={0,0};
    }

    if(vis[i][j]==1)


}


int main(){
    cin>>n>>m>>k;
    f0r(i,0,n){
        f0r(j,0,m){
            cin>>a[i][j];
            dp[i][j]=-1;
        }
    }
    int x = f(); 
}