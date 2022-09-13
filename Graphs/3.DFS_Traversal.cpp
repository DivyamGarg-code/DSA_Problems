#include<bits/stdc++.h>
using namespace std;
/*
Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
*/
bool compare(vector<int> a,vector<int> b){
    return a<b;
}
void dfs(unordered_map<int,set<int>> &adj,unordered_map<int,bool> &visited,int node,vector<int> &temp){
    temp.push_back(node);
    visited[node]=true;
    for(int x:adj[node]){
        if(!visited[x]){
            dfs(adj,visited,x,temp);
        }
    }
    return;
}
vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges){
    unordered_map<int,set<int>> adj;
    vector<vector<int>> ans;
    for(auto x:edges){
        int u=x[0];
        int v=x[1];
        adj[u].insert(v);
        adj[v].insert(u);
    }
    // for(int i=0;i<v;i++){
    //     cout<<i<<" -> ";
    //     for(auto x:adj[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    unordered_map<int,bool> visited;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            vector<int> temp;
            dfs(adj,visited,i,temp);
            ans.push_back(temp);
        }
    }
    sort(ans.begin(),ans.end(),compare);
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
    depthFirstSearch(n,m,edges);
    return 0;
}