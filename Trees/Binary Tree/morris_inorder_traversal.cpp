#include<bits/stdc++.h>
using namespace std;

/*
MORRIS TRAVERSAL INORDER
TIME COMPLEXITY O(N)
SPACE COMPLEXITY O(N)
Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
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

Node* find(Node* current){
    Node* temp=current->left;
    while(temp->right!=NULL && temp->right!=current){
        temp=temp->right;
    }
    return temp;
}
void morrisTraversal(Node* root){
    if(root==NULL){
        return;
    }
    Node* predecessor;
    Node* current=root;
    while(current!=NULL){
        if(current->left==NULL){ // If left part dont exist
            cout<<current->data<<" ";
            current=current->right;
        }else{ // If the left part exist find the predecessor
            predecessor=find(current);
            if(predecessor->right==NULL){
                predecessor->right=current;
                current=current->left;
                // current=current->right; for preorder
            }else{
                predecessor->right=NULL;
                cout<<current->data<<" ";
                current=current->right;
                // current=current->left; for preorder
            }
        }
    }
}
int main(){
    Node* root=buildTree();
    morrisTraversal(root);
}

/*
Using Morris Traversal, we can traverse the tree without using stack and recursion. The idea of Morris Traversal is based on Threaded Binary Tree. In this traversal, we first create links to Inorder successor and print the data using these links, and finally revert the changes to restore original tree. 

1. Initialize current as root 
2. While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Find rightmost node in current left subtree OR
              node whose right child == current.
         If we found right child == current
             a) Update the right child as NULL of that node whose right child is current
             b) Print current’s data
             c) Go to the right, i.e. current = current->right
         Else
             a) Make current as the right child of that rightmost 
                node we found; and 
             b) Go to this left child, i.e., current = current->left
Although the tree is modified through the traversal, it is reverted back to its original shape after the completion. Unlike Stack based traversal, no extra space is required for this traversal.

Time Complexity : O(n) If we take a closer look, we can notice that every edge of the tree is traversed at most three times. And in the worst case, the same number of extra edges (as input tree) are created and removed.
*/