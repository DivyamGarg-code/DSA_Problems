#include<bits/stdc++.h>
using namespace std;

/*
Maximum Pair Sum IMPORTANT
https://www.geeksforgeeks.org/queries-for-greatest-pair-sum-in-the-given-index-range-using-segment-tree/
*/
void buildTree(int *a,vector<pair<int,int>> &tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode].first=a[start];
        tree[treeNode].second=a[start];
        return;
    }
    int mid=start+(end-start)/2;
    buildTree(a,tree,start,mid,2*treeNode);
    buildTree(a,tree,mid+1,end,2*treeNode+1);
    // After left and right subtree is being built
    int max_l=tree[2*treeNode].first; // maximum  number in the left subtree
    int max_r=tree[2*treeNode+1].first; // maximum number in the right subtree
    int pair_sum_left=tree[2*treeNode].second; // maximum  pair sum in the left subtree
    int pair_sum_right=tree[2*treeNode].second;// maximum pair sum in the right subtree
    tree[treeNode].first=max(max_l,max_r);
    if((max_l+max_r)>max(pair_sum_left,pair_sum_right)){
        tree[treeNode].second=max_l+max_r;
    }else{
        tree[treeNode].second=max(pair_sum_left,pair_sum_right);
    }
}

void updateTree(int *a,vector<pair<int,int>> &tree,int start,int end,int treeNode,int idx,int value){
    if(start==end){
        a[idx]=value;
        tree[treeNode].first=a[start];
        tree[treeNode].second=a[start];
        return;
    }
    int mid=start+(end-start)/2;
    if(idx>mid){
        updateTree(a,tree,mid+1,end,2*treeNode+1,idx,value);
    }else{
        updateTree(a,tree,start,mid,2*treeNode,idx,value);
    }
    // After left and right subtree is being built
    int max_l=tree[2*treeNode].first; 
    int max_r=tree[2*treeNode+1].first; 
    int pair_sum_left=tree[2*treeNode].second; 
    int pair_sum_right=tree[2*treeNode].second;
    tree[treeNode].first=max(max_l,max_r);
    if((max_l+max_r)>max(pair_sum_left,pair_sum_right)){
        tree[treeNode].second=max_l+max_r;
    }else{
        tree[treeNode].second=max(pair_sum_left,pair_sum_right);
    }
}

pair<int,int> query(vector<pair<int,int>> &tree,int start,int end,int treeNode,int left,int right){
    if(start>right || end<left){ // Completely outside
        return {INT_MIN,INT_MIN};
    }
    if(start>=left && end<=right){ // Completely inside
        return tree[treeNode];
    }
    int mid=start+(end-start)/2;
    pair<int,int> ans1=query(tree,start,mid,2*treeNode,left,right);
    pair<int,int> ans2=query(tree,mid+1,end,2*treeNode+1,left,right);
    pair<int,int> ans;
    ans.first=max(ans1.first,ans2.first);
    if((ans1.first+ans2.first)>max(ans1.second,ans2.second)){
        ans.second=ans1.first+ans2.first;
    }else{
        ans.second=max(ans1.second,ans2.second);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // pair(max,pair_sum);
    vector<pair<int,int>> tree(4*n);
    buildTree(a,tree,0,n-1,1); 
    pair<int,int> ans=query(tree,0,n-1,1,0,4);
    cout<<ans.second;
}

