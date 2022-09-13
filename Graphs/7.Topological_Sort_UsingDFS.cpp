#include<bits/stdc++.h>
using namespace std;

// Topological Sorting
// https://www.geeksforgeeks.org/all-topological-sorts-of-a-directed-acyclic-graph/

void topoSort(unordered_map<int,list<int>> &adj,vector<bool> &visited,stack<int> &s,int i){
    visited[i]=true;
    for(auto x:adj[i]){
        if(!visited[x]){
            topoSort(adj,visited,s,x);
        }
    }
    s.push(i);
    return;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,list<int>> adj;
    for(auto x:edges){
        int u=x[0];
        int v=x[1];
        adj[u].push_back(v);
    }
    vector<bool> visited(v,false);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(adj,visited,s,i);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
    
}
int main(){
    int n,m;
    cout<<"Enter number of nodes\n";
    cin>>n;
    cout<<"Enter number of edges\n";
    cin>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        vector<int> temp;
        int x,y;
        cin>>x>>y;
        temp.push_back(x);
        temp.push_back(y);
        edges.push_back(temp);
    }
    topologicalSort(edges,n,m);
    return 0;
}