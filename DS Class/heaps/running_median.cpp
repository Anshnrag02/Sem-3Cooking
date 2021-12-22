#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>>minheap;
    priority_queue<int>maxheap;
    int temp;
    float median;
    while(n--){
        cin>>temp;
        if(minheap.size()==0 and maxheap.size()==0){
            maxheap.push(temp);
            median = temp;
        }
        else{
            if(temp>median){
                if(minheap.size()==maxheap.size()){
                    int a = minheap.top();
                    minheap.pop();
                    maxheap.push(a);
                }
                minheap.push(temp);
            }
            else if(temp<=median){
                if(minheap.size()<maxheap.size()){
                    int a = maxheap.top();
                    maxheap.pop();
                    minheap.push(a);
                }
                maxheap.push(temp);
            }
        }

        if(minheap.size()==maxheap.size()){
            median=(float)(minheap.top()+maxheap.top())/2;
        }
        else
            median=maxheap.top();
        cout<<median<<"\t";
    }
}