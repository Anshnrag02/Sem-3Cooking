#include<bits/stdc++.h>
using namespace std;

int findMax(set<int> my_set)
{
  
    // Get the maximum element
    int max_element;
    if (!my_set.empty())
        max_element = *(my_set.rbegin());
  
    // return the maximum element
    return max_element;
}

int a[10000],b[10000];

int main(){
    int t; cin>>t;
    while(t--){
        int n ; cin>>n;
        // bool f=false;
        for(int i = 0 ; i < n ; ++i){
            cin>>a[i];
        }
        set<int>s;
        for(int i = 0 ; i < n ; ++i){
            cin>>b[i];
        }
        bool f=0;
        for(int i = 0 ; i < n ; ++i){
            if(a[i]<b[i]){
                f=1;
                break;
            }
            else{
                if(b[i]!=0){
                    s.insert(a[i]-b[i]);
                }
                else{
                    if(a[i]>)
                }
            }
        }

        if(s.size()>1 or f==1)
            cout<<"NO\n";
        else
            cout<<"YES\n";

    }
}