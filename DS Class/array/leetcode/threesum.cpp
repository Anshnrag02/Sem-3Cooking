#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>>ans,fans;
        if(a.size()<3){
            return ans;
        }
        int n =  a.size();
        sort(a.begin(),a.end());
        for(int i = 0 ; i < n ; ++i){
            int j=1+i,k=n-1;
            while(j<k){
                if(a[j]+a[k]+a[i]==0){
                    if(ans.size()==0)
                        ans.push_back({a[i],a[j],a[k]});
                    else{
                        if(ans[ans.size()-1][0]!=a[i] or ans[ans.size()-1][1]!=a[j]){
                            ans.push_back({a[i],a[j],a[k]});
                        }
                    }
                    j++;k--;
                }
                else if(a[j]+a[k]+a[i]>0){
                    k--;
                }
                else{
                    j++;
                }
            }
            while(i<n-2){
                if(a[i]==a[i+1]){
                    i++;
                }else{
                    break;
                }
            }
        }
    return ans;
        
    }
};