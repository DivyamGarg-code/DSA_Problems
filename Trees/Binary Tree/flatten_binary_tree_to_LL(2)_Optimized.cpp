#include<bits/stdc++.h>
using namespace std;

/*
MORE OPTIMIZED USING MORRIS TRAVERSAL
TIME COMPLEXITY O(N)
SPACE COMLEXITY O(1)
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

void flattenTree(Node* root){
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left!=NULL){ // If left node exist
        // find the predecessor and connect it with the curr->right
            Node* pred=curr->left; 
            while(pred->right!=NULL){
                pred=pred->right;
            }
            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
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
    flattenTree(root);
    print(root);

}

