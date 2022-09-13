#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY O(N)
// SPACE COMPLEXITY O(Height of tree)
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

pair<Node*,Node*> flattenBSTtoLL(Node* &root){ // pair(head,tail)
    if(root==NULL){
        return {NULL,NULL};
    }
    pair<Node*,Node*> left=flattenBSTtoLL(root->left);
    pair<Node*,Node*> right=flattenBSTtoLL(root->right);
    if(left.first==NULL && right.first==NULL){
        return {root,root};
    }else if(left.first!=NULL && right.first==NULL){
        left.second->right=root;
        return {left.first,root};
    }else if(left.first==NULL && right.first!=NULL){
        root->right=right.first;
        return {root,right.second};
    }else{
        left.second->right=root;
        root->right=right.first;
        return {left.first,right.second};
    }
}

void print(Node* root){
    if(root==NULL){
        return;
    }
    Node* temp=root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}
int main(){
    Node* root=takeInput();
    print(flattenBSTtoLL(root).first);
    return 0;
}