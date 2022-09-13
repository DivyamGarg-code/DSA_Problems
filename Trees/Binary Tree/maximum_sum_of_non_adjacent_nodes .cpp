#include<bits/stdc++.h>
using namespace std;

// Maximum sum of non adjacent nodes 
/*
TIME COMPLEXITY O(N)
SPACE COMPLEXITY O(Height of tree)

Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.
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

// pair<maxSum by including the nodes at current level,maxSum by excluding the nodes at current level>
pair<int,int> solve(Node* root){
    // base case
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=solve(root->left);
    pair<int,int> right=solve(root->right);
    pair<int,int> ans;
    ans.first=root->data+left.second+right.second; // if we include the root's data we will not include it's children data
    ans.second=max(left.first,left.second)+max(right.first,right.second);
    return ans;
}

int getMaxSum(Node *root) {
    pair<int,int> ans=solve(root);
    return max(ans.first,ans.second);
}

int main(){
    Node* root=buildTree();

}