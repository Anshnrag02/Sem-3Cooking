#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    
        
        int *harr;
        int capacity;
        int heap_size;

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
            int i = heap_size;
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
                swap(harr[largest],harr[i]);
                heapify(largest);
            }
        }

        void itr_heapify(int i){
            int largest  = i ;
            while(i<heap_size){

                int l  =  left(i);
                int r  =  right (i);

                if(l<heap_size and harr[largest]<harr[l]){
                    largest = l;
                }
                
                if(r<heap_size and harr[largest]<harr[r]){
                    largest = r;
                }
                if( largest != i ){
                    swap(harr[largest],harr[i]);
                    i=largest;
                }
                else{
                    break;
                }
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

        void heapsort(){
            int n = heap_size;
            vector<int> sorted;
            while(heap_size>0){
                swap(harr[0],harr[heap_size-1]);
                heap_size--;
                itr_heapify(0);    
            }
            heap_size = n;
        }

        void print(){
            for(int i=0; i<heap_size; i++){
                cout<<harr[i]<<" ";
            }
            cout<<endl;
        }

};

int main(){
    MaxHeap h(10);
    h.insertKey(3);
    h.print();
    h.insertKey(2);
    h.print();
    h.insertKey(15);
    h.print();
    h.insertKey(5);
    h.print();
    h.insertKey(4);
    h.print();
    h.insertKey(45);
    h.print();
    h.insertKey(12);
    h.print();
    h.insertKey(18);
    h.print();
    h.heapsort();
    h.print();
}