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

pair<Node*,Node*> search(Node* root,int x){ // pair(node to be deleted,it's predecessor)
    pair<Node*,Node*> p;
    Node* temp=NULL;
    if(root->data==x){
        p=make_pair(root,temp);
        return p;
    }
    while(root!=NULL){
        if(x==root->data){
            p=make_pair(root,temp);
            return p;
        }else if(x<root->data){
            temp=root;
            root=root->left;
        }else{
            temp=root;
            root=root->right;
        }
    }
    Node* t=NULL;
    p=make_pair(t,t);
    return p;
}

Node* findMin(Node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
pair<Node*,Node*> findMax(Node *root){
    Node* temp=NULL;
    while(root->right!=NULL){
        temp=root;
        root=root->right;
    }
    pair<Node*,Node*> p(root,temp);
    return p;
}
void deleteNode(Node* &root,int data){
    if(root==NULL){
        cout<<"Tree is empty\n";
        return;
    }
    pair<Node*,Node*> temp=search(root,data);
    Node* curr=temp.first;
    Node* pred=temp.second; // predecessor of the current node
    if(curr==NULL){
        cout<<"Enter Correct data\n";
        return;
    }
    if(curr->left==NULL && curr->right==NULL){ // o child (leaf node)
        if(pred==NULL){
            root=NULL;
        }else{
            if(pred->left==curr){
                pred->left=NULL;

            }else{
                pred->right=NULL;

            }
        }
        delete curr;
    }else if(curr->left!=NULL && curr->right==NULL){ // 1 child
        if(pred==NULL){
            root=curr->left;
            delete curr;
        }else{
            if(pred->left==curr){
                pred->left=curr->left;
                delete curr;
            }else{
                pred->right=curr->left;
                delete curr;
            }
        }
    }else if(curr->left==NULL && curr->right!=NULL){
        if(pred==NULL){
            root=curr->right;
            delete curr;
        }else{
            if(pred->left==curr){
                pred->left=curr->right;
                delete curr;
            }else{
                pred->right=curr->right;
                delete curr;
            }
        }
    }else if(curr->left!=NULL && curr->right!=NULL){ // 2 child
        pair<Node*,Node*> p=findMax(curr->left);
        Node* maxNode=p.first;
        Node* pre=p.second;
        curr->data=maxNode->data;
        if(pre==NULL){  
            curr->left=maxNode->left;
        }else{
            pre->right=maxNode->left;
        }
        delete maxNode;
    }

}

int main(){
    Node* root=NULL;
    cout<<"Enter Data to create BST\n";
    takeInput(root);
    deleteNode(root,1110);
    print(root);
    return 0;
}