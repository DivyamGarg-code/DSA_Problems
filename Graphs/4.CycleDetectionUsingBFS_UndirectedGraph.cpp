#include<bits/stdc++.h>
using namespace std;
/*
CYCLE DETECTION USING BFS
Time complexity O(V+E)
*/
bool isCycleBFS(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,unordered_map<int,int> &parent,int i){
    queue<int> q;
    q.push(i);
    visited[i]=1;
    parent[i]=-1;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto x:adj[temp]){
            if(!visited[x]){
                q.push(x);
                visited[x]=1;
                parent[x]=temp;
            }else{ // this vertex is already visited
                if(parent[temp]!=x){
                    return true;
                }
            }
        }
        
    }
    return false;
}
string cycleDetection(vector<vector<int>>& edges, int n, int m){
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    for(auto x:edges){
        int u=x[0];
        int v=x[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // to handle dissconnected components
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool b=isCycleBFS(adj,visited,parent,i);
            if(b==true){
                return "Yes";
            }
        }
    }
    return "No";
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
    cout<<cycleDetection(edges,n,m);
    return 0;
}