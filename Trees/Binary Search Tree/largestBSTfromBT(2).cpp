#include<bits/stdc++.h>
using namespace std;
/*
    IMP QUESTION
    Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
    Note: Here Size is equal to the number of nodes in the subtree.

    APPROACH 2 OPTIMIZED 
    TC O(N)
    SC O(HEIGHT OF TREE)
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

class info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;

};

info solve(Node* root,int &ans){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0}; 
    }
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);

    info currNode; // Noe=w I'm standing on mycurrent node
    currNode.size=left.size+right.size+1;
    currNode.maxi=max(root->data,right.maxi); // as maximum right se nikalta ha
    currNode.mini=min(root->data,left.mini); // as minimum left se nikalta ha
    if(left.isBST && right.isBST && (root->data>left.maxi && root->data<right.mini)){
        currNode.isBST=true;
    }else{
        currNode.isBST=false;
    }

    // ans update
    if(currNode.isBST){
        ans=max(ans,currNode.size);
    }
    return currNode;
}
int largestBst(Node *root){
    int maxSize=0;
    info temp=solve(root,maxSize);
    return maxSize;
}
int main(){
    Node* root=takeInput();
    cout<<largestBst(root);
    return 0;
}