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

        void bft(int source){
            unordered_set<int>s;
            queue<int>q;
            q.push(source);
            s.insert(source);
            q.push(-1);
            while(!q.empty()){ 
                if(q.front()==-1){
                    q.pop();
                    if(!q.empty())
                        q.push(-1);
                    cout<<endl;
                }
                else{
                    cout<<q.front()<<" ";
                    for( int val : l[q.front()] ){
                        if(s.find(val)==s.end())
                        {
                            q.push(val);    
                        }
                        s.insert(val);
                    }
                    q.pop();
                }
            }
        }


};


int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(3,4);
    g.addEdge(3,6);
    g.bft(0);
}

//BFS 