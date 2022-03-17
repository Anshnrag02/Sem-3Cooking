#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin>>n; 
    vector<int>a(n),b(n);
    for(auto &x : a){
        cin>>x;
    }
    b[0]= -1;
    stack<int>s;
    s.push(0);
    for(int i = 1 ; i <n ; ++ i ){
        while(!s.empty() and a[s.top()]<a[i]){
            s.pop();
        }
        if(s.empty()){
            b[i]=-1;
        }
        else{
            b[i]=s.top();
        }
        
        s.push(i);
    }
    for(int i = 0 ; i < n; ++i)
        cout<<b[i]<<" ";    
}