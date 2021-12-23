#include<bits/stc++.h>

class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        if(a.size()==0){
            return 0;
        }
        
        int j=1,i=1;
        
        int n = a.size();
        
        for(; i<n ; i ++ ){
            if(a[i]!=a[i-1]){
                a[j]=a[i];
                j++;
            }
        }
        
        return j;
    }
};