#include<bits/stdc++.h>
using namespace std;

// Cycle Detection in Directed Graphs using DFS

#include<bits/stdc++.h>

bool checkCycleDFS(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,unordered_map<int,bool> &dfs_vis,int i){
    vis[i]=true;
    dfs_vis[i]=true;
    for(auto x:adj[i]){
        if(!vis[x]){ // not visited
            bool isCycleDetected=checkCycleDFS(adj,vis,dfs_vis,x);
            if(isCycleDetected){
                return true;
            }
        }else if(dfs_vis[x]){
            return true;
        }
    }
    dfs_vis[i]=false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    
    unordered_map<int,list<int>> adj;
    for(auto x:edges){
        int u=x.first;
        int v=x.second;
        adj[u].push_back(v);
    }
    // call DFS for all the components
    unordered_map<int,bool> vis;
    unordered_map<int,bool> dfs_vis;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            bool b=checkCycleDFS(adj,vis,dfs_vis,i);
            if(b==true){
                return true;
            }
        }
    }
    return false;
    
}

int main(){
    int n,m;
    cout<<"Enter number of nodes\n";
    cin>>n;
    cout<<"Enter number of edges\n";
    cin>>m;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        vector<int> temp;
        int x,y;
        cin>>x>>y;
        edges.push_back({x,y});
    }
    cout<<detectCycleInDirectedGraph(n,edges);
    return 0;
}