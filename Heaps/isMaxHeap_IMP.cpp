#include<bits/stdc++.h>
using namespace std;

//  IMPORTANT QUESTION
/* Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.
    TIME COMPLEXITY O(N)
    SPACE COMPLEXITY O(H)
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
int cntNodes(struct Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+cntNodes(root->left)+cntNodes(root->right);
}

// CHECK IF THE GIVEN BINARY TREE IS A COMPLETE BINARY TREE OR NOT
bool isCBT(struct Node* root,int i,int cnt){
    if(root==NULL){
        return true;
    }
    if(i>=cnt){
        return false;
    }
    bool left=isCBT(root->left,2*i+1,cnt);
    bool right=isCBT(root->right,2*i+2,cnt);
    return left&&right;
}

bool isMaxHeap(struct Node* root){
    // leaf node is already a heap
    if(root->left==NULL && root->right==NULL){ // leaf node
        return true;
    }else if(root->right==NULL){ // only left child exist
        return root->data>root->left->data;
    }else{ // both child exist
        bool left=isMaxHeap(root->left);
        bool right=isMaxHeap(root->right);
        return root->data>root->left->data && root->data>root->right->data && left && right;
    }
}

bool isHeap(struct Node* root) {
    int index=0;
    int totalcount=cntNodes(root);
    if(isCBT(root,index,totalcount) && isMaxHeap(root)){
        return true;
    }else{
        return false;
    }
    
}
int main(){
    Node* root=takeInput();
    cout<<isHeap(root);
    return 0;
}