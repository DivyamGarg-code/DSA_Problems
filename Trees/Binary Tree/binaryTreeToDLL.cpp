#include<bits/stdc++.h>
using namespace std;
/*
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

2 APPROACHES

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

void printLL(Node* root){
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->right;
    }
}

// TC O(n^2) SC O(h) H is the height of the tree and this space is used // implicitly for the recursion stack.

Node* convertIntoSortedDoublyLL(Node* root){
    if(root==NULL){
        return NULL;
    }
    Node* l=convertIntoSortedDoublyLL(root->left);
    Node* r=convertIntoSortedDoublyLL(root->right);
    if(l!=NULL && r!=NULL){
        root->right=r;
        r->left=root;
        Node* tail=l;
        while(tail->right!=NULL){
            tail=tail->right;
        }
        tail->right=root;
        root->left=tail;
        return l;
    }else if(l==NULL && r==NULL){
        return root;
    }else if(l!=NULL && r==NULL){
        Node* tail=l;
        while(tail->right!=NULL){
            tail=tail->right;
        }
        tail->right=root;
        root->left=tail;
        return l;
    }else if(l==NULL && r!=NULL){
        root->right=r;
        r->left=root;
        return root;
    }

}

// TC O(N)  SC O(h)
void DLL(Node* root,Node* &head,Node* &prev){
    if(root==NULL){
        return;
    }
    DLL(root->left,head,prev);
    if(prev==NULL){
        head=root;
        prev=root;
    }else{
        prev->right=root;
        root->left=prev;
        prev=root;
    }
    DLL(root->right,head,prev);
}
Node * bToDLL(Node *root){
    // your code here
    Node* head=NULL;
    Node* prev=NULL;
    DLL(root,head,prev);
    return head;
}
int main(){
    Node* root=NULL;
    takeInput(root);
   // printLL(convertIntoSortedDoublyLL(root));
    printLL(bToDLL(root));


    return 0;
}