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


void solve(Node* root,vector<int> &v){
    if(root==NULL){
        return;
    }
    solve(root->left,v);
    v.push_back(root->data);
    solve(root->right,v);
}

void fillPreorder(Node* &root,vector<int> v){ // node left right
    static int idx=0;
    if(root==NULL){
        return;
    }
    root->data=v[idx];
    idx++;
    fillPreorder(root->left,v);
    fillPreorder(root->right,v);
}
Node* convertBSTtoMinHeap(Node* root){
    vector<int> v;
    solve(root,v);
    int n=v.size();
    fillPreorder(root,v);
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
int main(){
    Node* root=takeInput();
    convertBSTtoMinHeap(root);
    return 0;
}