#include<bits/stdc++.h>
using namespace std;

void buildTree(int *a,int *tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode]=a[start];
        return;
    }
    int mid=start+(end-start)/2;
    buildTree(a,tree,start,mid,2*treeNode);
    buildTree(a,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}

void updateTree(int *a,int *tree,int start,int end,int treeNode,int idx,int value){
    if(start==end){
        a[idx]=value;
        tree[treeNode]=value;
        return;
    }
    int mid=start+(end-start)/2;
    updateTree(a,tree,start,mid,2*treeNode,idx,value);
    updateTree(a,tree,mid+1,end,2*treeNode+1,idx,value);
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}

/* 
condition left<=right
3 CASES
COMPLETELY OUTSIDE -> return 0
COMPLETELY INSIDE -> return tree[treeNode]
PARTIALLY INSIDE PARTIALLY OUTSIDE-> call further to left subtree and right subtree
*/

int query(int *tree,int start,int end,int treeNode,int left,int right){
    if(start>right || end<left){ // completely outside
        return 0;
    }
    if(start>=left && end<=right){ // completely inside
        return tree[treeNode];
    }
    // if none of the above conditions is true ie the l,r lies partially therfore we have to call further
    // PARTIALLY INSIDE AND PARTIALLY OUTSIDE
    int mid=start+(end-start)/2;
    int ans1=query(tree,start,mid,2*treeNode,left,right);
    int ans2=query(tree,mid+1,end,2*treeNode+1,left,right);
    return ans1+ans2;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int *tree=new int[4*n];
    buildTree(a,tree,0,n-1,1); // buildTree(given_array,building_Tree,starting_index,ending_index,current_index)
    for(int i=1;i<2*(n+1);i++){
        cout<<"idx ->"<<i<<" "<<tree[i]<<endl;
    }
    cout<<endl;
    buildTree(a,tree,0,n-1,1);
    // Here in query left and right will be be between 0 to n-1 ie index of array
    int ans=query(tree,0,n-1,1,2,4);
    cout<<"Sum between range 2-4 "<<ans;
    return 0;
}