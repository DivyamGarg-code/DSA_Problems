#include<bits/stdc++.h>
using namespace std;

// Prim's Algorithm To find Minnimum Spanning Tree
// TIME COMPLEXITY O(N^2) Brute Force
// can be optimised usung priority queue
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    unordered_map<int,list<pair<int,int>>> adj;
    for(auto x:g){
        pair<pair<int,int>,int> t=x;
        int u=x.first.first;
        int v=x.first.second;
        int weight=x.second;
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
    vector<int> key(n+1,INT_MAX);
    vector<bool> mst(n+1,false);
    vector<int> parent(n+1,-1);
    key[1]=0;
    for(int i=1;i<=n;i++){
        int mini=INT_MAX;
        int u;
        for(int j=1;j<=n;j++){
            if(mst[j]==false && key[j]<mini){
                mini=key[j];
                u=j;
            }   
        }
        mst[u]=true;
        for(auto x:adj[u]){
            if(mst[x.first]==false && x.second<key[x.first]){
                key[x.first]=x.second;
                parent[x.first]=u;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++){
        cout<<parent[i]<<" "<<i<<" "<<key[i]<<endl;
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<pair<int, int>, int>> g;
    for(int i=0;i<m;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        pair<int,int> p={u,v};
        pair<pair<int, int>,int> t={p,weight};
        g.push_back(t);
    }
    calculatePrimsMST(n,m,g);
    return 0;
}