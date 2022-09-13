#include<bits/stdc++.h>
using namespace std;

int main(){
    // adjecency list of the weighted graph
    list<pair<int,int>> *l;
    int v; // v-> number of vertices
    cin>>v;
    l=new list<pair<int,int>>[v];
    int e; // e->number of edges
    cin>>e;
    for(int i=0;i<e;i++){
        int x,y,wt; // x--->y  weight of that edge
        cin>>x>>y>>wt;
        l[x].push_back(make_pair(y,wt)); // considering the graph having bidirectional edges
        l[y].push_back(make_pair(x,wt));
    }

    // Print the linked list
    for(int i=0;i<v;i++){
        // Print the every LL
        cout<<"Linked List "<<i<<"-> ";
        for(auto xp:l[i]){
            cout<<"("<<xp.first<<","<<xp.second<<") ";
        }
        
        cout<<endl;
    }

    return 0;
}