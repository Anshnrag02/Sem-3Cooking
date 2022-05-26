//Pair Friends or keep them single


//DP approach O(n)

#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

int main(){
    
        int n;
        cin>>n;
        vi a(n+1);
        for(int i = 1 ; i <= n ; ++i){
            if(i<=2){
                a[i]=i;
            }
            else{
                a[i]=a[i-1]+(i-1)*a[i-2];
            }
        }
        cout<<a[n];
}