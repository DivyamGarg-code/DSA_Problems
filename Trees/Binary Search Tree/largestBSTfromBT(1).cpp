#include<bits/stdc++.h>
using namespace std;
/*
    IMP QUESTION
    Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
    Note: Here Size is equal to the number of nodes in the subtree.

    APPROACH 1
    TC O(N^2)
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

Node* findMax(Node *root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

Node* findMin(Node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

pair<bool,int> isBST(Node* root,int &x){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    pair<bool,int> leftSubtree=isBST(root->left,x);
    pair<bool,int> rightSubtree=isBST(root->right,x);
    pair<bool,int> ans;
    ans.second=1+leftSubtree.second+rightSubtree.second;
    if(leftSubtree.first && rightSubtree.first){
        if(root->left!=NULL){ // Left part
            Node* max_element=findMax(root->left);
            if(max_element->data>=root->data){
                ans.first=false;
                return ans;
            }
        }
        if(root->right!=NULL){ // Right part
            Node* min_element=findMin(root->right);
            if(min_element->data<=root->data){
                ans.first=false;
                return ans;
            }
        }
        ans.first=true;
        if(ans.second>x){
            x=ans.second;
        }
        return ans;
    }else{
        ans.first=false;
        return ans;
    }
}

int largestBst(Node *root){
    int x=INT_MIN;
    isBST(root,x);
    return x;
}
int main(){
    Node* root=takeInput();
    cout<<largestBst(root);
    return 0;
}