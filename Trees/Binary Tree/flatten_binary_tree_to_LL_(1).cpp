#include<bits/stdc++.h>
using namespace std;

/*

Time Compexity O(n^2)
Space Complexity O(n)
Given a binary tree, flatten it into linked list in-place. Usage of auxiliary data structure is not allowed. After flattening, left of each node should point to NULL and right should contain next node in preorder.
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

Node* flattenTree(Node* root){
    if(root==NULL){
        return NULL;
    }
    // base case

    Node* leftSubtree=flattenTree(root->left); // return the 1st node of flatten left subtree
    Node* rightSubtree=flattenTree(root->right); // return the 1st node of flatten right subtree
    root->left=NULL;
    if(leftSubtree==NULL && rightSubtree==NULL){
        return root;
    }else if(leftSubtree!=NULL && rightSubtree!=NULL){
        Node* temp=leftSubtree;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        temp->right=rightSubtree;
        root->right=leftSubtree;
        return root;
    }else if(leftSubtree!=NULL && rightSubtree==NULL){
        root->right=leftSubtree;
        return root;
    }else{
        root->right=rightSubtree;
        return root;
    }
}

void print(Node* root){
    if(root==NULL){
        return ;
    }
    Node* temp=root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}

int main(){
    Node* root=buildTree();
    Node* ans=flattenTree(root);
    print(ans);

}

