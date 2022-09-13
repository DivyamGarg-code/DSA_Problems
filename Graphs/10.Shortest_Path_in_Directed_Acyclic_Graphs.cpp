#include<bits/stdc++.h>
using namespace std;
/*
Shortest Path in Directed Acyclic Graphs using Topological Sorting
TC O(V+E)
SC O(V+E)
*/
class Graph{
    public:
        unordered_map<int,list<pair<int,int>>> adj;
        void addEdge(int u,int v,int weight){
            adj[u].push_back({v,weight});
        }
        void printAdj(){
            for(auto x:adj){
                cout<<x.first<<" -> ";
                for(auto y:x.second){
                    cout<<"["<<y.first<<","<<y.second<<"] ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        void dfs(vector<bool> &visited,stack<int> &s,int i){
            visited[i]=true;
            for(auto x:adj[i]){
                if(!visited[x.first]){
                    dfs(visited,s,x.first);
                }
            }
            s.push(i);
            return;
        }

        void getShortestPath(int src,vector<int> &dist,stack<int> &s){
            dist[src]=0;
            cout<<s.size()<<endl;
            while(!s.empty()){
                int top=s.top();
                s.pop();
                if(dist[top]!=INT_MAX){
                    for(auto i:adj[top]){
                        if((dist[top]+i.second)<dist[i.first]){
                            dist[i.first]=(dist[top]+i.second);
                        }
                    }
                }
            }
        }

};
int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    g.printAdj();
    int n=6;
    // topological sort
    vector<bool> visited(n,false);
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(visited,s,i);
        }
    }
    vector<int> dist(n,INT_MAX);
    int src;
    cout<<"Enter the source from which you want to find the shortest distance to all vertices\n";
    cin>>src;
    g.getShortestPath(src,dist,s);
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}