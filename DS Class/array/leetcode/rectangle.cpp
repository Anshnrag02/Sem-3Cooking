#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        stack<int>s;
        s.push(0);
        int max_area = a[0],area = a[0];
        for(int i = 1 ; i < n; ++i){
            cout<<max_area;
            if(a[s.top()]<a[i]){
                s.push(i);
            }
            else{
                while(!s.empty() and a[s.top()]>=a[i]){
                    int height = a[s.top()];
                    s.pop();
                    area=height*(i-s.top()+1);
                    max_area=max(area,max_area);
                }
                s.push(i);
            }
        }
        return max_area;
}


int main(){
    vector<int>a = {2,1,5,6,2,3};
    cout<<largestRectangleArea(a);
}