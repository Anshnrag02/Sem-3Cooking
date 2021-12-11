#include<bits/stdc++.h>
using namespace std;

class MinHeap{

    private:

        int *harr;
        int capacity;
        int heap_size;

    public:

        MinHeap(int cap){
            heap_size = 0;
            capacity = cap;
            harr = new int[cap];
        }

        void MinHeapify(int);
        
        int parent(int i){
            return (i-1)/2;
        }

        int leftchild(int i){
            return 2*i+1;
        }

        int rightchild(int i){
            return 2*i+2;
        }

        int extractMin();
        
        int getMin(){
            return harr[0]; 
        };

        void decreaseKey(int i, int new_value);

        void deleteKey(int i);

        int minropes();

        void insertKey(int k);
};

int MinHeap::minropes(){
    int temp = 0;
    while(heap_size>1){
        int min = extractMin();
        int min2 = extractMin();
        insertKey(min+min2);
        temp+=min+min2;
        cout<<temp<<" "<<heap_size<<endl;
    }
    return temp;
}

void MinHeap::insertKey(int k){
    if (heap_size == capacity){
        cout<<"Condition overflow\n";
        return;
    }

    int i = heap_size;
    harr[i]=k;
    heap_size++;
    while(i!=0 and harr[parent(i)]>harr[i]){
        swap(harr[parent(i)],harr[i]);
        i=parent(i);
    }
}

void MinHeap::decreaseKey(int i , int key){
    harr[i] = key;
    while(i!=0 and harr[parent(i)]>harr[i]){
        swap(harr[parent(i)],harr[i]);
        i=parent(i);
    }
}

int MinHeap::extractMin(){
    if (heap_size <= 0){
        return INT_MAX;
    }
    if (heap_size == 1){
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[--heap_size];
    MinHeapify(0);

    return root;
}

void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}



//heapifying one node
void MinHeap::MinHeapify(int i){
    int smallest = i ;
    int l = leftchild(i);
    int r = rightchild(i);

    if(l < heap_size && harr[smallest]>harr[l]){
        smallest = l;
    }

    if(r < heap_size && harr[smallest]>harr[r]){
        smallest = r;
    }
    if(i!=smallest){
        swap(harr[i],harr[smallest]);
        MinHeapify(smallest);
    }
}

// Driver program to test above functions
int main()
{
    MinHeap h(6);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(4);
    h.insertKey(6);
    cout << h.minropes();
    return 0;
}