#include<bits/stdc++.h>

class Solution {
public:
    
    int leftchild(int n){
        return 2*n+1;
    }
    
    int rightchild(int n){
        return 2*n+2;
    }
    
    
    void minheapify(vector<vector<int>>& points,vector<int>&heap,int i){
        int temp = i;
        int smallest =temp;
        int l = leftchild(temp);
        int r = rightchild(temp);
        if(l < heap.size()){ if(points[heap[smallest]][0]*points[heap[smallest]][0]+points[heap[smallest]][1]*points[heap[smallest]][1]>points[heap[l]][0]*points[heap[l]][0]+points[heap[l]][1]*points[heap[l]][1]){
            smallest = l;
        }}

        if(r < heap.size()){ if(points[heap[smallest]][0]*points[heap[smallest]][0]+points[heap[smallest]][1]*points[heap[smallest]][1]>points[heap[r]][0]*points[heap[r]][0]+points[heap[r]][1]*points[heap[r]][1]){
            smallest = r;
        }}
        
        if(i!=smallest){
            swap(heap[i],heap[smallest]);
            minheapify(points,heap,smallest);
        }
    }
    
    void buildheap(vector<vector<int>>& points,vector<int>&heap){
        for(int i = (heap.size()-2)/2 ; i>=0 ; i--){
            minheapify(points,heap,i);
        }
    }
           
    int extractmin(vector<vector<int>>& points,vector<int>& heap){
        int root = heap[0];
        swap(heap[0],heap[heap.size()-1]);
        heap.pop_back();
        minheapify(points,heap,0);
        return root;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int>heap;
        for(int i = 0 ; i < points.size(); i++){
            heap.push_back(i);
        }
        buildheap(points,heap);
        vector<vector<int>> ans;
        while(k--){
            int idx = extractmin(points,heap);
            ans.push_back(points[idx]);
        }        
        return ans;
    }
};

/*
class Solution {
public:
    class Compare{
        public:
            bool operator()(vector<int>a,vector<int>b){
                return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
            }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,Compare>heap;
        for(int i=0; i<k; i++){
            heap.push(points[i]);
        }
        for(int i=k; i<points.size(); i++){
            int x=points[i][0];
            int y=points[i][1];
            int x1=heap.top()[0];
            int y1=heap.top()[1];
            if(x*x+y*y<x1*x1+y1*y1){
                heap.pop();
                heap.push(points[i]);
            }
        }
        vector<vector<int>>ans;
        while(heap.size()){
            ans.push_back(heap.top());
            heap.pop();
        }
        return ans;
    }
};

*/
