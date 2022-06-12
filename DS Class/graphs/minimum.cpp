#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
bool vis[1001][1001];
vector<pair<int,int>>ans;
int n , m, maxi=INT_MIN;

void traverse(int i , int j){
    
    vis[i][j]=1;
    
    if(i>0 and vis[i-1][j]==0 and a[i-1][j]<=a[i][j]){
        traverse(i-1,j);
    }
    if(j>0 and vis[i][j-1]==0 and a[i][j-1]<=a[i][j]){
        traverse(i,j-1);
    }
    if(j<m-1 and vis[i][j+1]==0 and a[i][j+1]<=a[i][j]){
        traverse(i,j+1);
    }
    if(j<n-1 and vis[i+1][j]==0 and a[i+1][j]<=a[i][j]){
        traverse(i+1,j);
    }

}

int main(){
    cin>>n>>m;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cin>>a[i][j];
            vis[i][j]=0;
            maxi=max(a[i][j],maxi);
        }
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(a[i][j]==maxi and !vis[i][j]){
                ans.push_back({i,j});
                traverse(i,j);
            }
        }
    }

    // cout<<ans.size();

    for(int i = 0 ; i < ans.size() ; ++i){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}