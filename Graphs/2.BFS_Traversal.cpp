#include<bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int,set<int>> &adjList,vector<pair<int, int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void bfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        // store the frontNode into ans
        ans.push_back(frontNode);
        for(auto i:adjList[frontNode]){
            if(visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
vector<int> BFS(int &n, vector<pair<int, int>> &edges){
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;
    prepareAdjList(adjList,edges);
    // traverse all components of a graph
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}
int main(){
    int n,m;
    cout<<"Enter number of nodes\n";
    cin>>n;
    cout<<"Enter number of edges\n";
    cin>>m;
    vector<pair<int, int>> edges;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edges.push_back({x,y});
    }
    vector<int> ans=BFS(n,edges);
    for(auto x:ans){
        cout<<x<<" ";
    }
     
    return 0;
}