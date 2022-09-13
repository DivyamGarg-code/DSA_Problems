#include<bits/stdc++.h>
using namespace std;

// Check if the 2 trees are identical or not

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


int sumNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    int l=sumNodes(root->left);
    int r=sumNodes(root->right);
    int currNode=root->data;
    return currNode+l+r;
}

// Time complexity O(n^2)
bool isSumTree(Node* root){ 
    if(root==NULL){
        return true;
    }
    bool leftAns=isSumTree(root->left);
    bool rightAns=isSumTree(root->right);
    int l=sumNodes(root->left);
    int r=sumNodes(root->right);
    int currNode=root->data;
    if(leftAns && rightAns && ((currNode==l+r) || (l==0 && r==0))){
        return true;
    }
    return false;

}

// MORE OPTIMISED TIME COMPLEXITY O(n)
// will return the pair of bool and sum of all the nodes including the current node as root node
pair<bool,int> sumTree(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    pair<bool,int> leftSubtree=sumTree(root->left);
    pair<bool,int> rightSubtree=sumTree(root->right);
    bool leftAns=leftSubtree.first;
    bool rightAns=rightSubtree.first;
    int l=leftSubtree.second;
    int r=rightSubtree.second;
    int currNode=root->data;
    pair<bool,int> ans;
    ans.second=currNode+l+r;
    if(leftAns && rightAns && ((currNode==l+r) || (l==0 && r==0))){
        ans.first=true;
    }else{
        ans.first=false;
    }
    return ans;
}
bool isSumtree(Node* root){
    return sumTree(root).first;
}
int main(){
    Node* root=buildTree();
    cout<<isSumTree(root);
    return 0;
}