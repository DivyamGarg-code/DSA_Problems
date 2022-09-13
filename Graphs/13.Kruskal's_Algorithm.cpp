#include<bits/stdc++.h>
using namespace std;

// Time Complexity O(mlog(m))
// Space Complexity O(n)

#include<bits/stdc++.h>
bool cmp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}
void makeSet(vector<int> &parent,vector<int> &rank,int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}
int findParent(vector<int> &parent,int node){
    if(parent[node]==node){ // You reached the final parent
        return node;
    }
    return parent[node]=findParent(parent,parent[node]); // path compression
}

void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
    u=findParent(parent,u);
    v=findParent(parent,v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }else if(rank[v]<rank[u]){
        parent[v]=u;
    }else{
        parent[v]=u;
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n){
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);
    int minWeight=0;
    for(int i=0;i<edges.size();i++){
         int u=findParent(parent,edges[i][0]);
         int v=findParent(parent,edges[i][1]);
        int wt=edges[i][2];
        if(u!=v){
            minWeight+=wt;
            unionSet(u,v,parent,rank);
        }
    }
    return minWeight;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        edges.push_back({u,v,weight});
    }
    cout<<minimumSpanningTree(edges,n);
    return 0;
}