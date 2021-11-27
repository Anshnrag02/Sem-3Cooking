#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    
        int heap_size;
        int *harr;
        int capacity;

    public:

        MaxHeap(int cap){
            heap_size = 0 ; 
            capacity = cap;
            harr = new int[cap];
        }
  
        int parent(int i) { return (i-1)/2; }
    
        // to get index of left child of node at index i
        int left(int i) { return (2*i + 1); }
    
        // to get index of right child of node at index i
        int right(int i) { return (2*i + 2); }

        void insertKey(int key){
            if(heap_size == capacity){
                cout<<"Cond'n Ovrflw\n";
                return;
            }
            int i = heap_size-1;
            harr[i] = key;
            heap_size++;
            
            while(i!=0 and harr[i]>harr[parent(i)]){
                swap(harr[i],harr[parent(i)]);
                i = parent(i);
            }
        }
        
        void heapify(int i){
            int largest  = i ;
            int l  =  left(i);
            int r  =  right (i);

            if(l<heap_size and harr[largest]<harr[l]){
                largest = l;
            }
            
            if(r<heap_size and harr[largest]<harr[r]){
                largest = r;
            }
            if( largest != i ){
                swap(harr[largest],harr[i])
                heapify(largest);
            }
        }

        void increaseKey(int i , int value){
            
            harr[i] = value;

            while(i!=0 and harr[i]>harr[parent(i)]){
                swap(harr[i],harr[parent(i)]);
                i = parent(i);
            }
        }

        int extractMax(){
            if (heap_size <= 0 ){
                return INT_MIN;
            }
            if(heap_size == 1){
                heap_size--;
                return harr[0];
            }
            int root = harr[0];
            harr[0] = harr[--heap_size];
            heapify(0);

            return root;
        };

        void deleteKey(int i){
            increaseKey(i, INT_MAX);
            extractMax();
        }

        int getMax() { 
            return harr[0]; 
        }
};

int main(){
    
}