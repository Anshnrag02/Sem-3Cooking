#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a,long int target,int start) {
        vector<vector<int>>ans,fans;
        if(a.size()<3){
            return ans;
        }
        int n =  a.size();
        sort(a.begin(),a.end());
        for(int i = start ; i < n ; ++i){
            int j=1+i,k=n-1;
            while(j<k){
                long int temp = a[j]+a[i];
                temp+=a[k];
                if(temp==target){
                    if(ans.size()==0)
                        ans.push_back({a[i],a[j],a[k]});
                    else{
                        if(ans[ans.size()-1][0]!=a[i] or ans[ans.size()-1][1]!=a[j]){
                            ans.push_back({a[i],a[j],a[k]});
                        }
                    }
                    j++;k--;
                }
                else if(temp>target){
                    k--;
                }
                else{
                    j++;
                }
            }
            while(i<n-1){
                if(a[i]==a[i+1]){
                    i++;
                }else{
                    break;
                }
            }
        }
    return ans;
        
    }
    
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int>>ans;
        if(a.size()<=3){
            return ans;
        }
        int n =  a.size();
        sort(a.begin(),a.end());
        for(int i = 0 ; i < n-3 ; ++i){
            int j = ans.size();
            vector<vector<int>>fans=(threeSum(a,target-a[i],i+1));
            for(int f = 0 ; f < fans.size(); f++){
                ans.push_back(fans[f]);
            }
            for(; j  < ans.size() ; j++ ){
                
                ans[j].push_back(a[i]);
            }
            while(i<n-3){
                if(a[i]==a[i+1]){
                    i++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }