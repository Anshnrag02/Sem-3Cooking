//Find Hamiltonian Path
//Backtracking

#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
bool adj[1000][1000];
int n,k;

bool hamp(int node, unordered_set<int>s){
    if(s.size()==n){
        
        return 1;
    }
    for(int i = 0 ; i < n ; ++i){
        if(adj[node][i]==1 and s.find(i)==s.end()){
            s.insert(i);
            if(hamp(i,s)){
                return 1;
            }
            s.erase(i);
        }
    }

    return false;

}

int main(){
    
    cin>>n>>k;
    int temp = k;
    while(temp--){
        int a,b;
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
    for(int i=0; i<n ; ++i){
        unordered_set<int>s;
        s.insert(i);
        if(hamp(i,s)){
            cout<<"yes";
            return 0;
        }
    }
    cout<<"no";
}