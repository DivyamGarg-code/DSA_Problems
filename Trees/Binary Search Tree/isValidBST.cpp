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

Node* findMax(Node *root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

Node* findMin(Node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

// Recursive approach
bool isBST(Node* root){
    if(root==NULL){
        return true;
    }
    bool leftSubtree=isBST(root->left);
    bool rightSubtree=isBST(root->right);
    if(leftSubtree && rightSubtree){
        if(root->left!=NULL){ // Left part
            Node* max_element=findMax(root->left);
            if(max_element->data>root->data){
                return false;
            }
        }
        if(root->right!=NULL){ // Right part
            Node* min_element=findMin(root->right);
            if(min_element->data<root->data){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

// More efficient method
// TC O(N) SC O(Height if tree)
bool isValidBST(Node* root,int min,int max){
    // base case
    if(root==NULL){
        return true;
    }
    if(root->data>min && root->data<max){
        bool left=isValidBST(root->left,min,root->data);
        bool right=isValidBST(root->right,root->data,max);
        return left && right;
    }else{
        return false;
    }
}

int main()
{
    Node* root = NULL;
    takeInput(root);

    return 0;
}