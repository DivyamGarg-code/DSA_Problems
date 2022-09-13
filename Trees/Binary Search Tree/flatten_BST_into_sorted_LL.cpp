#include<bits/stdc++.h>
using namespace std;
// Flatten a BST into a sorted LL

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

// TC O(N) SC O(N) where n is the total number of nodes
void solve(Node* root,vector<Node*> &v){
    if(root==NULL){
        return;
    }
    solve(root->left,v);
    v.push_back(root);
    solve(root->right,v);
}
void printBST(Node* root){
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->right;
    }
}
void flatenBST(Node* root){
    vector<Node*> v;
    solve(root,v);
    int n=v.size();
    if(n==0){
        return;
    }else{
        for(int i=0;i<n-1;i++){
            v[i]->left=NULL;
            v[i]->right=v[i+1];
        }
        v[n-1]->left=NULL;
        v[n-1]->right=NULL;
    }
    printBST(v[0]);

}

// Using Recursion
// Time complexity O(N) Space complexity O(height of tree) More optimized
Node* flatten(Node* &root){
    if(root==NULL){
        return NULL;
    }
    Node* l=flatten(root->left);
    Node* r=flatten(root->right);
    if(l!=NULL && r!=NULL){
        Node* temp=l;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        temp->right=r;
        root->right=l;
        root->left=NULL;
        return root;
    }else if(l==NULL && r==NULL){
        return root;
    }else if(l!=NULL && r==NULL){
        root->right=l;
        root->left=NULL;
        return root;
    }else if(l==NULL && r!=NULL){
        return root;
    }
}
int main(){
    Node* root=NULL;
    takeInput(root);
    flatenBST(root);
    return 0;
}