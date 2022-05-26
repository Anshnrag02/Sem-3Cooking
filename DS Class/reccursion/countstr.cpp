//Count Binary Strings with No Consecutive 1s 


//DP approach O(n)

#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

int main(){
    
        int n;
        cin>>n;
        vi a0(n+1),a1(n+1);
        a0[0]=0;
        a1[0]=0;
        a0[1]=1;
        a1[1]=1;
        for(int i =2 ; i <=n ; ++i){
            a0[i]=a0[i-1]+a1[i-1];
            a1[i]=a0[i-1];
        }
        cout<<a0[n]+a1[n];

}