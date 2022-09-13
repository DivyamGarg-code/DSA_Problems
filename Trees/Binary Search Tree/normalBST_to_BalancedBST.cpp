#include<bits/stdc++.h>
using namespace std;
// Convert a normal BST to Balanced BST
// BASICALLY CONVERTING INORDER TO BST
// Given a BST (Binary Search Tree) that may be unbalanced, convert it into // a balanced BST that has minimum possible height.
// TC O(n) SC O(n)
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

void insertIntoBST(Node* &root,int data){
    if(root==NULL){
        root=new Node(data);
        return;
    }
    Node* temp=root;
    while(temp!=NULL){
        if(data<=temp->data){
            if(temp->left==NULL){
                Node* n=new Node(data);
                temp->left=n;
                return;
            }else{
                temp=temp->left;
            }
        }else{
            if(temp->right==NULL){
                Node* n=new Node(data);
                temp->right=n;
                return;
            }else{
                temp=temp->right;
            }
        }
    }
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
    }
}

void print(Node* root){
    if(root==NULL){
        return ;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

void solve(Node* root,vector<Node*> &v){
    if(root==NULL){
        return;
    }
    solve(root->left,v);
    v.push_back(root);
    solve(root->right,v);
}
Node* makeBalancedBST(int s,int e,vector<Node*> &v){
    if(s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    Node* root=new Node(v[mid]->data);
    Node* l=makeBalancedBST(s,mid-1,v);
    Node* r=makeBalancedBST(mid+1,e,v);
    root->left=l;
    root->right=r;
    return root;
}
void balancedBST(Node* root){
    vector<Node*> v;
    solve(root,v);
    for(auto x:v){
        x->left=NULL;
        x->right=NULL;
    }
    Node* temp=makeBalancedBST(0,v.size()-1,v);
    print(temp);
}
int main(){
    Node* root=NULL;
    takeInput(root);
    balancedBST(root);
    return 0;
}