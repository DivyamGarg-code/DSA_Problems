#include<bits/stdc++.h>
using namespace std;


#include<bits/stdc++.h>

bool isCycleDFS(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,int parent,int node){
    visited[node]=1;
    for(auto x:adj[node]){
        if(!visited[x]){
            bool isCycleDetected=isCycleDFS(adj,visited,node,x);
            if(isCycleDetected){
                return true;
            }
        }else if(parent!=x){
            // cycle is present;
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m){
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;
    int parent;
    for(auto x:edges){
        int u=x[0];
        int v=x[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // to handle dissconnected compnents
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool b=isCycleDFS(adj,visited,-1,i);
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