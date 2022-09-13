#include<bits/stdc++.h>
using namespace std;

// Check if the 2 trees are identical or not

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
// Time Complexity: O(N).
// Auxiliary Space: O(Height of the Tree).
bool isIdentical(Node* r1,Node* r2){
    if((r1==NULL && r2!=NULL) || (r2==NULL && r1!=NULL)){
        return false;
    }
    if(r1==NULL && r2==NULL){
        return true;
    }
    bool leftsubtree=isIdentical(r1->left,r2->left);
    bool rightSubtree=isIdentical(r1->right,r2->right);
    if(leftsubtree && rightSubtree && r1->data==r2->data){
        return true;
    }
    return false;
}
int main(){
    Node* root1=buildTree();
    Node* root2=buildTree();
    cout<<isIdentical(root1,root2);
    return 0;
}