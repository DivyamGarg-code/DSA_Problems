#include<bits/stdc++.h>
using namespace std;

// DIJKSTRA'S ALGORITHM (VERY IMPORTANT)
// TIME COMPLEXITY O(E*LOG(V))
// SPACE COMPLEXITY O(N+E)
// Weighted Undirected Graph
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // create adjacency list
    unordered_map<int,list<pair<int,int>>> adj;
    for(auto x:vec){
        int u=x[0];
        int v=x[1];
        int weight=x[2];
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }
    for(auto x:adj){
        cout<<x.first<<" -> ";
        for(auto y:x.second){
            cout<<"["<<y.first<<","<<y.second<<"] ";
        }
        cout<<endl;
    }

    set<pair<int,int>> s; // pair(distance to reach this vertix,vertix)
    vector<int> dist(vertices,INT_MAX);
    dist[source]=0;
    s.insert({0,source});
    while(!s.empty()){
        pair<int,int> top=*s.begin();
        int d=top.first;
        int vertex=top.second;
        s.erase(s.begin());
        for(auto x:adj[vertex]){
            if((d+x.second)<dist[x.first]){
                if(s.find({dist[x.first],x.first})!=s.end()){
                    // remove the old distance if present
                    s.erase({dist[x.first],x.first});
                }
                // distance update
                dist[x.first]=(d+x.second);

                s.insert({dist[x.first],x.first});
            }
        }
    }
    for(int i=0;i<vertices;i++){
        cout<<dist[i]<<" ";
    }
    return dist;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec;
    for(int i=0;i<m;i++){
        vector<int> temp;
        int u,v,weight;
        cin>>u>>v>>weight;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(weight);
        vec.push_back(temp);
    }
    dijkstra(vec,n,m,0);
    return 0;
}