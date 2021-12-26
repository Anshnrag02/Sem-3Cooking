#include<bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> a, int k) {
        map<int,int>mp;
        vector<int>sum,l_sum;
        int n = a.size();
        int s_count=0,temp=0;
        l_sum.push_back(0);
        for(int i = 1 ; i <= n ; ++i ){
            sum.push_back(a[i-1]%k);
        }
        for(int i = 0 ; i<n ; ++ i ){
            l_sum.push_back(((l_sum[i])%k+(sum[i])%k)%k);
        }
        for(int i = 0 ; i<=n ; ++ i ){
            l_sum[i]=l_sum[i]%k;
            if(l_sum[i]<0){
                l_sum[i]=k+l_sum[i];
            }
            temp+=mp[l_sum[i]];
            mp[l_sum[i]]++;
        }
        for(int i =  0 ; i < l_sum.size() ; i++){
            cout<<l_sum[i]<<" ";
        }
        cout<<endl;
        return temp;
}

int main(){
    cout<<subarraysDivByK({4,5,0,-2,-3,1},5)<<endl;;

    cout<<(-7)%5;
}