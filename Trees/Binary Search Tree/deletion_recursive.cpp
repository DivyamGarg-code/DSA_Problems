#include<bits/stdc++.h>
using namespace std;

// Deletion of node in O(N) time and O(1) space

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

// INSERTION IN O(N) TIME AND O(1) SPACE
void insertintoBST(Node* &root,int data){
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
        insertintoBST(root,data);
        cin>>data;
    }
}
void print(Node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

Node* findMin(Node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* findMax(Node *root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

Node* deleteFromBST(Node* root,int val){
    // base case
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }else if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }else if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }else{
            Node* max_element=findMax(root->left);
            root->data=max_element->data;
            root->left=deleteFromBST(root->left,max_element->data);
            return root;
            
        }
    }else if(val<root->data){
        root->left=deleteFromBST(root->left,val);
        return root;
    }else{
        root->right=deleteFromBST(root->right,val);  
        return root; 
    }
}
int main(){
    Node* root=NULL;
    cout<<"Enter Data to create BST\n";
    takeInput(root);
    Node* ans=deleteFromBST(root,100);
    print(ans);
    return 0;
}