#include<bits/stdc++.h>

vector<int>wordsolver(vector<string>words){
    vector<int>ans;
    for(string a:words){
        int cnt  = 1; 
        int n = a.length();
        int temp = 0 ; 
        for(int i = 1 ; i < n ; ++ i){
            if(a[i]==a[i-1]){
                cnt++;
            }
            else{
                temp+=(cnt/2);
                cnt = 1;
            }
        }
        if(cnt!=0){
            temp+=(cnt/2);
        }
        ans.push_back(temp);
    }
    return ans;
}