#include<bits/stdc++.h>
using namespace std;

// Constructing a binary tree from inorder and preorder
// TC O(n^2)

// You can optimize the solution by using map for storing the indices
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

void printTree(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data<<" ";
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);

}
Node* construct(int* in,int *pre,int s_in,int e_in,int s_pre,int e_pre){
    if(s_in>e_in){
        return NULL;
    }
    int idx=-1;
    int rootData=pre[s_pre];
    for(int i=s_in;i<=e_in;i++){
        if(rootData==in[i]){
            idx=i;
            break;
        }
    }
    
    Node* root=new Node(pre[s_pre]);
    Node* leftChild=construct(in,pre,s_in,idx-1,s_pre+1,s_pre+idx-s_in);
    Node* rightChild=construct(in,pre,idx+1,e_in,s_pre+idx-s_in+1,e_pre);
    root->left=leftChild;
    root->right=rightChild;
    return root;
}

Node* buildTree(int in[],int pre[], int n){
    Node* root=construct(in,pre,0,n-1,0,n-1);
    return root;
}
int main(){
    int n=4;
    int in[]={1,6,8,7};
    int pre[]={1,6,7,8};
    Node* root=buildTree(in,pre,n);
    printTree(root);
    return 0;
}