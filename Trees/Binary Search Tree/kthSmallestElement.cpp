#include <bits/stdc++.h>
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
void print(Node* root)
{
    if (root == NULL) {
        return;
    }
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int solve(Node* root,int &i,int k){ // just see like solving in inorder manner
    if(root=NULL){
        return -1;
    }
    int left=solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->right,i,k);

}

// TC O(n)
// SC O(height of tree)
int kthSmallest(Node* root,int k){
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}

Node* find(Node* root,Node* curr){
    if(root==NULL){
        return NULL;
    }
    while(root->right!=NULL && root->right!=curr){
        root=root->right;
    }
    return root;
}

// TC O(n) SC O(1) kthSmallest using Morris Traversal
int KthSmallestElement(Node *root, int k) {
    if(root==NULL){
        return -1;
    }
    int i=0;
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            i++;
            if(i==k){
                return curr->data;
            }
            curr=curr->right;
        }else{
            Node* pred=find(curr->left,curr);
            if(pred->right==NULL){
                pred->right=curr;
                curr=curr->left;
            }else{
                pred->right=NULL;
                i++;
                if(i==k){
                    return curr->data;
                }
                curr=curr->right;
            }
        }
    }
    return -1;
}
int main()
{
    Node* root = NULL;
    takeInput(root);
    cout<<KthSmallestElement(root,2);
    return 0;
}