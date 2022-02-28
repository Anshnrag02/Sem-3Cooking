#include<bits/stdc++.h>
#include<list>
using namespace std;

class Node{
    public:
        string name;
        list<string>nbrs;
        Node(string name){
            this->name = name;
        }
};

class Graph{

    //all nodes
    //hashmap string->node*
    unordered_map<string , Node*>m;
    
    public:
        Graph(vector<string> cities){
            for ( auto city : cities){
                m[city] = new Node(city);
            }
        }

        void addEdge(string x, string y, bool undir = true){
            m[x]->nbrs.push_back(y);
            if(undir){
                m[y]->nbrs.push_back(x);
            }
        }

        void printlist(){
            for (auto [k,v]:m){
                cout<<k<<"----->";
                for(auto nbr: v->nbrs){
                    cout<<nbr<<",";
                }
                cout<<"\n";
            }
        }
};

int main(){
    Graph g({"Delhi", "Rome", "Paris","Goa"});

    g.addEdge("Delhi","Goa");
    g.addEdge("Delhi","Rome");
    g.addEdge("Paris","Rome");
    g.addEdge("Delhi","Paris");
    g.addEdge("Goa","Rome");
    g.printlist();


}