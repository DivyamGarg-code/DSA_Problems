#include<bits/stdc++.h>
using namespace std;

// Creating Graph using ADJACENCY LIST
// Checkout this for time and space complexity
// https://www.geeksforgeeks.org/comparison-between-adjacency-list-and-adjacency-matrix-representation-of-graph/
template<typename T>
class graph{
        unordered_map<T,list<T>> adj;
    public:
        void addEdge(T u,T v,bool direction){
            // directon->0 means undirected graph 
            // direction->1 means directed graph

            // create an edge from u->v
            adj[u].push_back(v);
            if(direction==0){ // u->v and v->u
                adj[v].push_back(u);
            }
        }
        void printAdjList(){
            for(auto i:adj){
                cout<<i.first<<" -> ";
                for(auto j:i.second){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }

};

int main(){
    int n;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    int m;
    cout<<"Enter the number of edges\n";
    cin>>m;
    graph<int> g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // creating an undirected graph
        g.addEdge(u,v,0);
    }
    g.printAdjList();
    return 0;
}