#include<bits/stdc++.h>
using namespace std;

class KaryMaxHeap
{
    int *arr;
    int capacity;
    int heap_size;
    int k;

    public:

        KaryMaxHeap(int cap, int k)
        {
            this->k = k;
            this->capacity = cap;
            heap_size = 0;
            arr = new int[cap];
        }
        
        void maxHeapify(int i);

        void buildMaxHeap();
        
        void heapIncreaseKey(int i, int key);
        
        void heapDecreaseKey(int i, int key);
        
        void heapDelete(int i);

        void heapInsert(int key);

        int parent(int i){return (i-1)/k;};
        
        int extractMax();
        
        int getMax(){return arr[0];};
        
        void print(){
            for(int i=0;i<heap_size;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
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

void KaryMaxHeap::heapIncreaseKey(int i , int key){
    if(key < arr[i]){
        cout<<"New key is smaller than current key"<<endl;
        return;
    }
    arr[i] = key;
    while(i > 0 and arr[parent(i)] < arr[i]){
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void KaryMaxHeap::heapDecreaseKey(int  i ,   int key){
    if(key > arr[i]){
        cout<<"New key is greater than current key"<<endl;
        return;
    }
    arr[i] = key;
    maxHeapify(i);
}

void KaryMaxHeap::heapDelete(int i){
    heapIncreaseKey(i, INT_MAX);
    extractMax();
}

int KaryMaxHeap::extractMax(){
    if(heap_size < 1){
        cout<<"Heap underflow"<<endl;
        return INT_MIN;
    }
    int root = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    maxHeapify(0);
    return root;
}

void KaryMaxHeap::heapInsert(int key){
    if(heap_size == capacity){
        cout<<"Heap overflow"<<endl;
        return;
    }
    heap_size++;
    int i = heap_size-1;
    arr[i] = key;
    while(i > 0 and arr[parent(i)] < arr[i]){
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }    
}

int main(){
    KaryMaxHeap heap(10, 3);
    heap.heapInsert(5);
    heap.print();
    heap.heapInsert(3);
    heap.print();
    heap.heapInsert(17);
    heap.print();
    heap.heapInsert(10);
    heap.print();
    heap.heapInsert(84);
    heap.print();
    heap.heapInsert(19);
    heap.print();
    heap.heapInsert(6);
    heap.print();
    heap.heapInsert(22);
    heap.print();
    heap.heapDelete(3);
    heap.print();
}