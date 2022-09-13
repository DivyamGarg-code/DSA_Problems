#include<bits/stdc++.h>
using namespace std;

/*
In segment tree the only thing you need to remember is segment tree ke hr node main kya store karna ha
*/
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
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int *tree=new int[4*n];
    // Always build tree of size 4*n for safer side
    // because indexing start from 1...n and n correspons to 2*n and 2*n+1 th index therfore size of array will be (2*n+1)+1 which is 2*(n+1)
    buildTree(arr,tree,0,n-1,1); // buildTree(given_array,building_Tree,starting_index,ending_index,current_index)
    for(int i=1;i<2*(n+1);i++){
        cout<<"idx ->"<<i<<" "<<tree[i]<<endl;
    }
    return 0;
}