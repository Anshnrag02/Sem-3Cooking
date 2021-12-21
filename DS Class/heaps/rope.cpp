#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>>pq;
    int temp;
    while(n--){
        cin>>temp;
        pq.push(temp);
    }
    int a,b,sum  = 0 ; 
    while(pq.size()>1){
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        sum+=(a+b);
        pq.push(a+b);
    }
    cout<<sum;
}