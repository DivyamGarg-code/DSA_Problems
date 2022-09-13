#include<bits/stdc++.h>
using namespace std;

// Find a pair with given target in BST 
// TC O(N) SC O(N)
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

void solve(Node* root,vector<int> &v){
    if(root==NULL){
        return;
    }
    solve(root->left,v);
    v.push_back(root->data);
    solve(root->right,v);
}
void isPairPresent(Node* root,int target){
    vector<int> v;
    solve(root,v);
    int ans=0;
    int i=0;
    int j=v.size()-1;
    while(i<j){
        int temp=v[i]+v[j];
        if(temp==target){
            cout<<v[i]<<" "<<v[j];
            return;
        }else if(temp<target){
            i++;
        }else{
            j--;
        }
    }
    cout<<0;
    return;
}

int main(){
    Node* root=NULL;
    takeInput(root);
    int a;
    cin>>a;
    isPairPresent(root,a);
    return 0;
}