#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int>s,e;bool f = 0 ;


int a[1001][1001];
int d[1001][1001];

bool fill(int i , int j , int dist){
    if(i<0 or j<0 or j>=n or i>=n)
        return false;
    if(d[i][j]!=-1){
        return false;
    }
    if(a[i][j]==0){
        d[i][j]=INT_MAX;
        return false;
    }

    d[i][j]=dist+1;

    if(a[i][j]==2){
        f=1;
        cout<<d[i][j];
        return 0;
    }
    return 1;

}

int main(){
    cin>>n;
    
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cin>>a[i][j];
            d[i][j]=-1;
            if(a[i][j]==1){
                s={i,j};
                d[i][j]=0;
            }        
        }
    }
    
    queue<pair<int,int>> q;
    q.push(s);
    while(!q.empty() and f==0){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(fill(x+1,y,d[x][y]))
            q.push({x+1,y});
        if(fill(x-1,y,d[x][y]))
            q.push({x-1,y});
        if(fill(x,y-1,d[x][y]))
            q.push({x,y-1});
        if(fill(x,y+1,d[x][y]))
            q.push({x,y+1});


    }

    if(!f){
        cout<<"-1";
    }

}