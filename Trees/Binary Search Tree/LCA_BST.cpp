#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void insertintoBST(Node*& root, int data)
{
    if (root == NULL) {
        root = new Node(data);
        return;
    }
    Node* temp = root;
    while (temp != NULL) {
        if (data <= temp->data) {
            if (temp->left == NULL) {
                Node* n = new Node(data);
                temp->left = n;
                return;
            }
            else {
                temp = temp->left;
            }
        }
        else {
            if (temp->right == NULL) {
                Node* n = new Node(data);
                temp->right = n;
                return;
            }
            else {
                temp = temp->right;
            }
        }
    }
}

void takeInput(Node*& root)
{
    int data;
    cin >> data;
    while (data != -1) {
        insertintoBST(root, data);
        cin >> data;
    }
}


// TC O(N) SC O(HEIGHT OF TREE) as we are doing through recursion 
Node* lca(Node* root,int a,int b){
    if(root==NULL){
        return NULL;
    }
    if(a<root->data && b<root->data){ // ie a and b lies in the left subtree
        lca(root->left,a,b);
    }else if(a>root->data && b>root->data){  // ie a and b lies in the right subtree
        lca(root->right,a,b);
    }else{
        return root;
    }
}

// More efficient way or iterative approach
// TC O(N) SC O(1)
Node* lowestCommonAncestor(Node* root,int a,int b){
    if(root==NULL){
        return NULL;
    }
    while(root!=NULL){
        if(a<root->data && b<root->data){ // ie a and b lies in the left subtree
            root=root->left;
        }else if(a>root->data && b>root->data){  // ie a and b lies in the right subtree
            root=root->right;
        }else{
            return root;
        }
    }
    return NULL;
}

int main(){
    Node* root=NULL;
    takeInput(root);
    int a,b;
    cin>>a>>b;
    cout<<lowestCommonAncestor(root,a,b)->data;
    return 0;
}