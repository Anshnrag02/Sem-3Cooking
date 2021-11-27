#include<bits/stdc++.h>
using namespace std;

int main(){
    int s=12;
    vector<int>a={1,2,3,4,5,6,7,8,9,10};
    vector<pair<int , int>> result;
    for(int i = 0 ; i < a.size() ; ++i ){
        int j=i+1,k=a.size()-1;
        pair<int, int>p;
        while(j<k){
            if(a[i]+a[j]+a[k]==s){
                p.first=a[i];
                p.second = a[j];
                result.push_back(p);
                j++;
                k--;
            }
            else if(a[i]+a[j]+a[k]>s){
                k--;
            }
            else{
                j++;
            }
        }
    }
    for(int i = 0 ; i < result.size() ; i ++ ){
        cout<<result[i].first<<","<<result[i].second<<","<<s-result[i].first-result[i].second<<"\n";
    }
}