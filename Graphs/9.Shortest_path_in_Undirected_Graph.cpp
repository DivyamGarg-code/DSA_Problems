#include<bits/stdc++.h>
using namespace std;

// Shortest Path in Undirected  and Unweighted Graph
// TC O(N+E)
// SC O(N+E)
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    vector<int> adj[n+1];
    for(auto x:edges){
        int u=x.first;
        int v=x.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n+1,false);
    vector<int> parent(n+1,-1);
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i:adj[front]){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=front;
                q.push(i);
            }
        }
    }
    // prepare shortest path
    vector<int> ans;
    int currentNode=t;
    ans.push_back(t);
    while(currentNode!=s){
        currentNode=parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n,m,s,t;
    cout<<"Enter number of nodes\n";
    cin>>n;
    cout<<"Enter number of edges\n";
    cin>>m;
    cout<<"Enter starting point\n";
    cin>>s;
    cout<<"Enter ending point\n";
    cin>>t;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edges.push_back({x,y});
    }
    shortestPath(edges,n,m,s,t);
    return 0;
}
