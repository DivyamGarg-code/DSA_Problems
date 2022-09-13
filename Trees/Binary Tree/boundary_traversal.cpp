#include<bits/stdc++.h>
using namespace std;
#define ll long long

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

void traverseLeft(Node* root,vector<int> &ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left!=NULL){
        traverseLeft(root->left,ans);
    }else{
        traverseLeft(root->right,ans);
    }
}

void traverseLeaf(Node* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

void traverseRight(Node* root,vector<int> &ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->right!=NULL){
        traverseRight(root->right,ans);
    }else{
        traverseRight(root->left,ans);
    }
    ans.push_back(root->data);
}
vector<int> boundaryTraversal(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);
    
    //left part print/store
    traverseLeft(root->left, ans);
    
    //traverse Leaf Nodes
    
    //left subtree
    traverseLeaf(root->left, ans);
    //right subtree
    traverseLeaf(root->right, ans);
    
    //traverse right part
    traverseRight(root->right, ans);
    
    return ans;
}

int main(){
    Node* root=buildTree();
    vector<int> v=boundaryTraversal(root);
    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;
}