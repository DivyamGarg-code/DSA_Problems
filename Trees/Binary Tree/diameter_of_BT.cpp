#include<bits/stdc++.h>
using namespace std;

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

void print(Node* root){ // preordr traversal
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void numLeafNodes(Node* root,int &cnt){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right==NULL){
        cnt+=1;
    }
    numLeafNodes(root->left,cnt);
    numLeafNodes(root->right,cnt);
}

int height(Node* root){ // Time complexity O(n) Space complexity O(height) ->which is the max height 
                            // from root to leaf
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}

// return the pair of diameter and height
// here we are not calculating the height seperately
// here the time complexity becomes O(n)
// space complexity O(height)->O(n) if the tree is skew
pair<int,int> diameterFast(Node* root){
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=diameterFast(root->left);
    pair<int,int> right=diameterFast(root->right);
    int op1=left.first;
    int op2=right.first;
    int op3=left.second+1+right.second;
    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}

int diameter_fast(Node* root){
    return diameterFast(root).first;
}

int diameter(Node* root){ // Here the time complexity will be O(n^2)
    if(root==NULL){
        return 0;
    }
    int op1=diameter(root->left); // either the diameter exists in the left subtree
    int op2=diameter(root->right); // either the diameter exists in the right subtree
    int op3=height(root->left)+1+height(root->right); // or the diameter exist in the both left and right subtree 
    int ans=max(op1,max(op2,op3));
    return ans;
}

 
int main(){
    Node* root=buildTree();
    int cnt=0;
    numLeafNodes(root,cnt);
    cout<<cnt;
    // printLevelWise(root);
    return 0;
}