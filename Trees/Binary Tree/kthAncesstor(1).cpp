#include<bits/stdc++.h>
using namespace std;

/*
TIME COMPLEXITY O(N)
SPACE COMPLEXITY O(H)
SOLVING USING VECTOR
Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.
 
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

void solve(Node* root,vector<int> v,int k,int data){
    if(root==NULL){
        return;
    }
    v.push_back(root->data);

    // left 
    solve(root->left,v,k,data);

    // right
    solve(root->right,v,k,data);

    // k th ancestor
    int n=v.size();
    if(v[n-1]==data){
        int x=n-k-1;
        if(x>=0){
            cout<<v[x];
        }else{
            cout<<-1;
        }
    }
}

int main(){
    
    Node* root=buildTree();
    vector<int> v;
    int k,data;
    cin>>k>>data;
    solve(root,v,k,data);

    return 0;
}