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

        void bft2(int source){
            queue<int> q;
            

            bool *visited = new bool[V]{0};
            int *dist = new int[V];
            int *parent = new int[V];

            for( int i=0 ; i<V ; ++i ){
                parent[i]=-1;
                dist[i]=INT_MAX;
            }

            parent[source]=source;
            dist[source]=0;
            
            q.push(source);
            visited[source]=1;

            while(!q.empty()){

                int f = q.front();
                cout<<f<<" ";
                q.pop();

                for(int nbr : l[f]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        dist[nbr]=dist[f]+1;
                        parent[nbr]=f;
                        visited[nbr]=1;
                    }
                }
            }
            //
            cout<<endl;
            for(int i = 0 ; i < V ; ++i){
                cout<<i<<"-->"<<dist[i]<<endl;
            }

            //
            for(int i = 0 ; i < V ; ++i){
                cout<<i<<"-->";
                int j = i;
                while(j!=parent[j])
                {
                    j=parent[j];
                    cout<<j<<" ";
                }
                cout<<endl;
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
    g.addEdge(5,6);
    g.bft2(6);
}

//BFS 