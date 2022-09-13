#include<bits/stdc++.h>
using namespace std;
/*
    THIS QUESTION IS VERY IMPORTANT CONCEPTUAL WISE
    MERGE 2 BST
    FLATTEN BST INTO SORTED DOUBLY LL
    MERGE THE 2 SORTED DOUBLY LL
    CREATE THE BST FROM THIS SORTED LL
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


// converting a BST into doubly LL 
// TC O(n) SC O(h)
void convertIntoSortedDoublyLL(Node* root,Node* &head){
    if(root==NULL){
        return ;
    }
    convertIntoSortedDoublyLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    convertIntoSortedDoublyLL(root->left,head);

}

Node* mergeLL(Node* head1,Node* head2){
    Node* head=NULL;
    Node* tail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
            }else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
            }
            head1=head1->right;
        }else{
            if(head==NULL){
                head=head2;
                tail=head2;
            }else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
            }
            head2=head2->right;
        }
    }
    while(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    while(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }
    return head;
}

int countNodes(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt+=1;
        temp=temp->right;
    }
    return cnt;
}

Node* sortedLLtoBST(Node* &head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    Node* left=sortedLLtoBST(head,n/2); // left subtree bna dega 
    Node* root=head;
    root->left=left;
    head=head->right;
    root->right=sortedLLtoBST(head,n-n/2-1);
    return root;
}

Node* mergeBST(Node* root1,Node* root2){
    // step1. convert BST into sorted DLL
    Node* head1=NULL;
    Node* head2=NULL;
    convertIntoSortedDoublyLL(root1,head1);
    head1->left=NULL;
    convertIntoSortedDoublyLL(root1,head2);
    head1->right=NULL;

    // step2. merge 2 sorted LL
    Node* head=mergeLL(head1,head2);

    // step3. convert sorted LL into BST
    return sortedLLtoBST(head,countNodes(head));

}
int main(){
    Node* root=NULL;
    takeInput(root);

    return 0;
}