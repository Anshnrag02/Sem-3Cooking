#include<bits/stdc++.h>

class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        
        
        if(n==0){
            return;
        }
        
        if(m==0){
            for(int p = 0 ; p < n ; p ++){
                a[p]=b[p];
            }
            return;
        }
        
        
        int i = 0, j = 0, k = m-1,numpass = 0 ;
        
        while(numpass<m and i<m and j<n){
            if(a[i]<b[j]){
                i++;
            }
            else{
                swap(b[j],a[k]);
                j++;k--;
            }
            numpass++;
        }
        j=0;
        i=m;
        sort(a.begin(),a.begin()+m);
        sort(b.begin(),b.begin()+n);
        while(i<m+n){
            a[i++]=b[j++];
            
        }
    }
};