#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int maxi;
        int second_maxi;
};

void buildTree(int *a,node &tree,int s,int e,int treeIndex){
    if(s==e){
        tree[treeIndex]->maxi=a[s];
        tree[treeIndex]->second_maxi=a[s];
    }
    int mid=s+(e-s)/2;
    buildTree(a,tree,s,mid,2*treeIndex);
    buildTree(a,tree,mid+1,e,2*treeIndex+1);

}
int main(){
    int n;
    cin>>n;
    int a[n]; 
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    node* tree=new node[3*n];
    buildTree(a,tree,0,n-1,1);
    for(int i=0;i<n;i++){
        cout<<i<<" -> "<<"max: "<<tree[i].maxi<<" "<<"second max: "<<tree[i].second_maxi<<endl;
    }

    return 0;
}