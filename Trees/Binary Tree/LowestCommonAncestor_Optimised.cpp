#include<bits/stdc++.h>
using namespace std;

// Lowest Common Ancestor
// Time complexity O(N)
// Space Complexity O(height of tree)
// Memory efficient Recursive Approach
// No need to make vector


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

Node* lca(Node* root,int n1,int n2){
    //base case
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftAns=lca(root->left,n1,n2);
    Node* rightAns=lca(root->right,n1,n2);
    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }else if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }else{
        return NULL;
    }
}
int main(){
    Node* root=buildTree();
    int n1,n2;
    cin>>n1>>n2;
    lca(root,n1,n2);
    return 0;
}