#include<bits/stdc++.h>
using namespace std;

// Merge 2 Binary tree
/*
https://leetcode.com/problems/merge-two-binary-trees/
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
};

Node* takeInput(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* root=new Node(data);
    root->left=takeInput();
    root->right=takeInput();
    return root;

}

void print(Node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

Node* mergeTrees(Node* root1, Node* root2) {
    if(root1!=NULL && root2!=NULL){
        root1->data=root1->data+root2->data;
    }else if(root1==NULL && root2==NULL){
        return NULL;
    }else if(root1!=NULL && root2==NULL){
        return root1;
    }else if(root1==NULL && root2!=NULL){
        return root2;
    }

    root1->left=mergeTrees(root1->left,root2->left);
    root1->right=mergeTrees(root1->right,root2->right);
    return root1;

}
int main(){
    Node* root1=takeInput();
    Node* root2=takeInput();
    Node* root3=mergeTrees(root1,root2);
    print(root3);
    return 0;
}