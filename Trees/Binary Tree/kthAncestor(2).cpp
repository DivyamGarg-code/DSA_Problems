#include<bits/stdc++.h>
using namespace std;

/*
TIME COMPLEXITY O(N)
SPACE COMPLEXITY O(H) due to stack space

SOLVING USING Recursion

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

Node* solve(Node* root,int &k,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        return root;
    }
    Node* leftAns=solve(root->left,k,data);
    Node* rightAns=solve(root->right,k,data);
    if(leftAns!=NULL && rightAns==NULL){
        k--;
        if(k==0){
            // k ko max karne ka reason is to lock the current node
            k=INT_MAX;
            return root;
        }
        return leftAns;
    }else if(leftAns==NULL && rightAns!=NULL){
        k--;
        if(k==0){
            k=INT_MAX;
            return root; 
        }
        return rightAns;
    }
}

int kthAncestor(Node *root, int k, int node){
    Node* ans=solve(root,k,node);
    if(ans==NULL || ans->data==node){
        return -1;
    }else{
        return ans->data;
    }
}
int main(){
    
    Node* root=buildTree();
    int k,data;
    cin>>data>>k;
    kthAncestor(root,k,data);

    return 0;
}
