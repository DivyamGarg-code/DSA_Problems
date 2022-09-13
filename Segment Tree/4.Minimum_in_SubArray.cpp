#include<bits/stdc++.h>
using namespace std;

// Find Minimum in the subarray from [l,r] 
void buildTree(int *a,int *tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode]=a[start];
        return;
    }
    int mid=start+(end-start)/2;
    buildTree(a,tree,start,mid,2*treeNode);
    buildTree(a,tree,mid+1,end,2*treeNode+1);
    // After left and right subtree is being built
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}

void updateTree(int *a,int *tree,int start,int end,int treeNode,int idx,int value){
    if(start==end){
        a[idx]=value;
        tree[treeNode]=value;
        return;
    }
    int mid=start+(end-start)/2;
    if(idx>mid){
        updateTree(a,tree,mid+1,end,2*treeNode+1,idx,value);
    }else{
        updateTree(a,tree,start,mid,2*treeNode,idx,value);
    }
    // After left and right subtree is being built
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}

int query(int *tree,int start,int end,int treeNode,int left,int right){
    if(start>right || end<left){ // Completely outside
        return INT_MAX;
    }
    if(start>=left && end<=right){ // Completely inside
        return tree[treeNode];
    }
    int mid=start+(end-start)/2;
    int ans1=query(tree,start,mid,2*treeNode,left,right);
    int ans2=query(tree,mid+1,end,2*treeNode+1,left,right);
    return min(ans1,ans2);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int *tree=new int[4*n];
    buildTree(a,tree,0,n-1,1);
    for(int i=1;i<2*(n+1);i++){
        cout<<"idx ->"<<i<<" "<<tree[i]<<endl;
    }
    cout<<endl;
    cout<<query(tree,0,n-1,1,2,4);
    return 0;
}