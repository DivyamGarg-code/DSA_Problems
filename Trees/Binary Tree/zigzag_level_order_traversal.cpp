#include<bits/stdc++.h>
using namespace std;
#define ll long long

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

void zigzagTraversal(Node* root){
    if(root==NULL){
        return ;
    }
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    q.push(NULL);
    int i=0;
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            if(q.empty()){
                break;
            }
            cout<<endl;
            if(i==0){
                i=1;
            }else{
                i=0;
            }
            q.push(NULL);
            continue;
        }
        if(i==0){
            cout<<temp->data<<" ";
        }else{
            cout<<s.top()->data<<" ";
            s.pop();
        }
        if(temp->left!=NULL){
            q.push(temp->left);
            if(i==0){
                s.push(temp->left);
            }
        }
        if(temp->right!=NULL){
            q.push(temp->right);
            if(i==0){
                s.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root=buildTree();
    zigzagTraversal(root);
    return 0;
}