#include<bits/stdc++.h>
using namespace std;

/*
Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.

*/
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            left=NULL;
            right=NULL;
        }
        ~Node(){
            delete left;
            delete right;
        }
};

Node* buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* root=new Node(data);
    Node* leftChild=buildTree();
    Node* rightChild=buildTree();
    root->left=leftChild;
    root->right=rightChild;
    return root;

}

void solve(Node* root,int &ans,vector<int> v,int x){
    if(root==NULL){
        return;
    }
    v.push_back(root->data);

    // left 
    solve(root->left,ans,v,x);

    // right
    solve(root->right,ans,v,x);

    // check for k sum
    int size=v.size();
    int sum=0;
    for(int i=size-1;i>=0;i--){
        sum+=v[i];
        if(sum==v[i]){
            ans+=1;
        }
    }
    v.pop_back();
}

int sumK(Node *root,int k){
    int ans=0;
    vector<int> v;
    solve(root,ans,v,k);
    return ans;
}
int main(){
    
    Node* root=buildTree();
    int k;
    cin>>k;
    sumK(root,k);

    return 0;
}