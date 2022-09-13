#include<bits/stdc++.h>
using namespace std;

/*
    Topological Sort Using BFS Khan's Algorithm
    TC O(V+E)
    SC O(V+E)
*/

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,list<int>> adj;
    vector<int> indegree(v,0);
    for(auto x:edges){
        int u=x[0];
        int v=x[1];
        adj[u].push_back(v);
        indegree[v]+=1;
    }
    // 0 indegree valon ko push kar do
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    // do bfs
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        // store it in the ans
        ans.push_back(front);
        
        // neighbour indegree update
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
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
