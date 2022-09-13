#include<bits/stdc++.h>
using namespace std;

// A tree is height balanced if difference between heights of left and right subtrees // is not more than one for all nodes of tree. 

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

int height(Node* root){ 
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}

// Time complexity O(n^2)
bool isBalanced(Node* root){
    if(root==NULL){
        return true;
    }
    bool leftAns=isBalanced(root->left);
    bool rightAns=isBalanced(root->right);
    bool diff=abs(height(root->left)-height(root->right))<=1;
    if(leftAns && rightAns && diff){
        return true;
    }
    return false;
}


// pair of bool and height
// Time complexity O(n)
pair<bool,int> isBalancedFast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    pair<bool,int> left=isBalancedFast(root->left);
    pair<bool,int> right=isBalancedFast(root->right);
    int leftAns=left.first;
    int rightAns=right.first;
    int l=left.second;
    int r=right.second;
    pair<bool,int> ans;
    ans.second=max(l,r)+1;
    if(leftAns && rightAns && abs(l-r)<=1){
        ans.first=true;
    }else{
        ans.first=false;
    }
    return ans;

}

bool isBalanced_Fast(Node* root){
    return isBalancedFast(root).first;
}

int main(){
    Node* root=buildTree();
    cout<<isBalanced(root);
    return 0;
}