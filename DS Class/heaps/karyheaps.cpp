#include<bits/stdc++.h>
using namespace std;

class KaryMaxHeap
{
    int *arr;
    int capacity;
    int heap_size;
    int k;
    public:
    
    void maxHeapify(int i);

    void buildMaxHeap();
    
    void heapIncreaseKey(int i, int key);
    void heapDecreaseKey(int i, int key);
    void heapDelete(int i);
    void heapInsert(int key);
    int parent(int i);
    int extractMax();
    int getMax();
    void print();
};

void KaryMaxHeap::maxHeapify(int i){
    int first_child = (k*i)+1;
    int last_child = first_child + k - 1;
    int largest = i;
    for(int j = first_child; j <= last_child; j++){
        if(arr[j] > arr[largest] and j <= heap_size){
            largest = j;
        }
    }
    if (largest != i){
        swap(arr[i], arr[largest]);
        maxHeapify(largest);
    }    
}

void KaryMaxHeap::buildMaxHeap(){
    for(int i = (heap_size-2)/k ; i >= 0; i--){
        maxHeapify(i);
    }
}

void KaryMaxHeap