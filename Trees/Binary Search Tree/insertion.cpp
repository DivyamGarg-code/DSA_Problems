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

// INSERTION TAKES O(N) TIME AND O(N) SPACE
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

// INSERTION IN O(log(n)) TIME for average case 
// in worst case insertion of n nodes will be O(n^2) in case of skew tree
// AND O(1) SPACE
// void insertintoBST(TreeNode* &root,int val){
//     if(root==NULL){
//         root=new TreeNode(val);
//         return;
//     }
//     TreeNode* temp=root;
//     while(temp!=NULL){
//         if(val<=temp->val){
//             if(temp->left==NULL){
//                 TreeNode* n=new TreeNode(val);
//                 temp->left=n;
//                 return;
//             }else{
//                 temp=temp->left;
//             }
//         }else{
//             if(temp->right==NULL){
//                 TreeNode* n=new TreeNode(val);
//                 temp->right=n;
//                 return;
//             }else{
//                 temp=temp->right;
//             }
//         }
//     }
// }

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
    return 0;
}