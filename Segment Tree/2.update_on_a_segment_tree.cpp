#include<bits/stdc++.h>
using namespace std;

// This takes O(n) time 
void buildTree(int *arr,int *tree,int start,int end,int treeNode){ 
    if(start==end){
        tree[treeNode]=arr[start];
        return;
    }
    int mid=start+(end-start)/2;
    buildTree(arr,tree,start,mid,2*treeNode); // build left tree
    buildTree(arr,tree,mid+1,end,2*treeNode+1); // build right tree
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}

void updateTree(int *arr,int *tree,int start,int end,int treeNode,int idx,int value){
    if(start==end){
        arr[idx]=value;
        tree[treeNode]=value;
        return;
    }
    int mid=start+(end-start)/2;
    if(idx>mid){
        updateTree(arr,tree,mid+1,end,2*treeNode+1,idx,value);
    }else{
        updateTree(arr,tree,start,mid,2*treeNode,idx,value);
    }
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1]; // put the updated value

}

int main(){
    // eg [1,2,3,,4,5]
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int *tree=new int[2*(n+1)];
    // build tree of size 2*(n+1)
    // because indexing start from 1...n and n correspons to 2*n and 2*n+1 th index therfore size of array will be (2*n+1)+1 which is 2*(n+1)
    buildTree(arr,tree,0,n-1,1); // buildTree(given_array,building_Tree,starting_index,ending_index,current_index)
    for(int i=1;i<2*(n+1);i++){
        cout<<"idx ->"<<i<<" "<<tree[i]<<endl;
    }
    cout<<endl;
    // update the value : log(n)
    arr[2]=10;
    updateTree(arr,tree,0,n-1,1,2,10);
    for(int i=1;i<2*(n+1);i++){
        cout<<"idx ->"<<i<<" "<<tree[i]<<endl;
    }
    return 0;
}