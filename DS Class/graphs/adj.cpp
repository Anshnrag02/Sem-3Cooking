#include<bits/stdc++.h>
#include<list>
using namespace std;

class Graph{
    private:

        list<int> *l; //pointer to an array of list
        int V;
    
    public:
    
        Graph(int v){
            V=v;
            l = new list<int>[V];
        }

        void addEdge(int i , int j, bool undir = true){
            l[i].push_back(j);
            if(undir)
                l[j].push_back(i);
        }

        void printAdjList(){
            for(int i = 0 ; i < V ; ++i){
                cout<<i<<" ----> ";
                for(int val : l[i])
                    cout<<val<<", ";
                cout<<"\n";
            }
        }


};


int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.printAdjList();
}