#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll int main(){
    ll int n,temp,area,max_area=ll int_MIN;
    cin>>n;
    stack<ll int>s;
    vector<ll int>a;
    for(ll int i = 0 ; i < n ; ++ i) {
        cin>>temp;
        a.push_back(temp);
    }
    s.push(0);
    for (ll int i = 1 ; i < n ; ++ i){
        if(a[i]>a[s.top()]){
            s.push(i);
        }
        else{
            while(a[s.top()]>=a[i]){
                temp = s.top();
                s.pop();
                if(s.empty())
                {
                    area=a[temp]*(i);
                    max_area=max(max_area,area);
                    break;
                }
                else{
                    area=a[temp]*(i-s.top()-1);
                
                    max_area=max(max_area,area);
                }
                
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        temp = s.top();
        s.pop();
        if(!s.empty())
            area=a[temp]*(n-s.top()-1);
        else
            area=a[temp]*n;
        max_area=max(max_area,area);
    }
    
    cout<<max_area;
}