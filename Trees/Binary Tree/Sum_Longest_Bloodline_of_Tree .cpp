#include<bits/stdc++.h>
using namespace std;

// Sum of nodes on the longest path from root to leaf node

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
void printNodes(Node* root,int &ans,vector<int> v){
    static int cnt=0;
    if(root==NULL){
        return;
    }
    v.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        if(v.size()>=cnt){
            cnt=v.size();
            int temp=accumulate(v.begin(), v.end(), 0);
            ans=max(ans,temp);
        }
        v.pop_back();
        return;
    }
    printNodes(root->left,ans,v);
    printNodes(root->right,ans,v);
}

int sumOfLongRootToLeafPath(Node *root){
    int ans=0;
    vector<int> v;
    printNodes(root,ans,v);
    return ans;
    
}

int main(){
    Node* root=buildTree();
    cout<<sumOfLongRootToLeafPath(root);
    return 0;
}