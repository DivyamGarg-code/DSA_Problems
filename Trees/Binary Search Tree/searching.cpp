#include<bits/stdc++.h>
using namespace std;

/*
INSERTION DELETION SEARCHING TAKES O(LOGN) TIME 
*/
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

Node* insertintoBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data<=root->data){ // left part main insert kr diya

        root->left=insertintoBST(root->left,data);

    }else{ // right part main insert kr diya
        root->right=insertintoBST(root->right,data);
    }

    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
          root=insertintoBST(root,data);
          cin>>data;
    }

}

// Searching recursively
// Time complexity O(logN) and O(N) in case of skew tree
// Space complexity O(height of tree)
// bool search(Node* root,int x){
//     if(root==NULL){
//         return false;
//     }
//     if(x==root->data){
//         return true;
//     }else if(x<root->data){
//         search(root->left,x);
//     }else{
//         search(root->right,x);
//     }
// }

// Iterative way searching SPACE COMPLEXITY O(1)
bool search(Node* root,int x){
    while(root!=NULL){
        if(x==root->data){
            return true;
        }else if(x<root->data){
            root=root->left;
        }else{
            root=root->right;
        }
    }
    return false;
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
    Node* root=NULL;
    cout<<"Enter Data to create BST\n";
    takeInput(root);
    print(root);
    cout<<search(root,34);

    return 0;
}