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

        int bfs(int dest){
            unordered_set<int>s;
            s.insert(0);
            queue<int>q;
            q.push(0);
            q.push(-1);
            int moves=0;
            while(!q.empty()){
                int f = q.front();
                q.pop();
                if(f==-1){
                    q.push(-1);
                    moves++;
                }
                else{
                    if(f==dest) 
                        return moves;
                    for(int nbr : l[f]){
                        if(s.find(nbr)==s.end())
                        {
                            s.insert(nbr);
                            q.push(nbr);
                        }
                    }
                }

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
    int n; cin>>n;
    vector<vector<int>>board(n,vector<int>(n));
    vector<vector<int>>snakes= {{13,7},{32,5}},ladders={{2,15},{18,23}};
    Graph G(n*n);
    for(int i = 0 ; i<n*n ; ++i){
        for(int j = 1; j <=6 ; ++j ){
            if(i+j<n*n){
                bool flag = 1;
                for(int k = 0 ; k<snakes.size() and flag ; k++){
                    if(snakes[k][0]==i+j){
                        flag = 0 ; 
                        G.addEdge(i,snakes[k][1],false);
                        break;
                    }
                }
                for(int k = 0 ; k<ladders.size() and flag ; k++){
                    if(ladders[k][0]==i+j){
                        flag = 0 ; 
                        G.addEdge(i,ladders[k][1],false);
                        break;
                    }
                }
                if(flag){
                    G.addEdge(i,i+j,false);
                }
            }
        }
    }


    cout<<G.bfs(23);

}

//BFS 