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

// Node* buildTree(){
//     int data;
//     cin>>data;
//     if(data==-1){
//         return NULL;
//     }
//     Node* root=new Node(data);
//     Node* leftChild=buildTree();
//     Node* rightChild=buildTree();
//     root->left=leftChild;
//     root->right=rightChild;
//     return root;
// }

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
Node* construct(int* in,int *post,int s_in,int e_in,int s_post,int e_post){
    if(s_in>e_in){
        return NULL;
    }
    int idx=-1;
    int rootData=post[s_post];
    for(int i=s_in;i<=e_in;i++){
        if(rootData==in[i]){
            idx=i;
            break;
        }
    }
    
    Node* root=new Node(rootData);
    Node* leftChild=construct(in,post,s_in,idx-1,s_post-(e_in-idx)-1,e_post);
    Node* rightChild=construct(in,post,idx+1,e_in,s_post-1,s_post-(e_in-idx));
    root->left=leftChild;
    root->right=rightChild;
    return root;
}

Node* buildTree(int in[],int post[], int n){
    Node* root=construct(in,post,0,n-1,n-1,0);
    return root;
}
int main(){
    int n=8;
    int in[]={4,8,2,5,1,6,3,7};
    int post[]={8,4,5,2,6,7,3,1};
    Node* root=buildTree(in,post,n);
    printTree(root);
    return 0;
}