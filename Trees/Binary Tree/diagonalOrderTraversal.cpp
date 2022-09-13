#include<bits/stdc++.h>
using namespace std;

// Vertical order traversal
// Here remenber one important point either you can store diagonal in a preorder manner or postorder
// Both will be correct
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



Node* buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* root=new Node(data);
    Node* leftChild=buildTree();
    Node* rightChild=buildTree();
    root->left=leftChild;
    root->right=rightChild;
    return root;

}

// Time complexity O(n)
int size(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSubtree=1+size(root->left);
    int rightSubtree=size(root->right);
    int ans= max(leftSubtree,rightSubtree);
    return ans;
}

void helper(Node* root, int d, vector<vector<int>> &v) { // preorder traversal
    if (root == NULL) return;
    v[d].push_back(root -> data);
    helper(root -> left, d + 1, v);
    helper(root -> right, d, v);
}
vector<int> diagonalTraversal(Node *root){
    int n=size(root);
    vector<vector<int>> v(n);
    helper(root, 0, v);
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            ans.push_back(v[i][j]);
        }
    }
    return ans;
}
int main(){
    Node* root=buildTree();
    diagonalTraversal(root);

}

// Hre diagonal will
// vector<int> diagonalTraversal(Node* root){
//     int n=size(root);
//     vector<vector<int>> v(n);
//     vector<int> ans;
//     queue<pair<Node*,int>> q;
//     q.push(make_pair(root,0));
//     while(!q.empty()){
//         pair<Node*,int> temp=q.front();
//         q.pop();
//         Node* frontNode=temp.first;
//         int d=temp.second;
//         v[d].push_back(frontNode->data);
//         if(frontNode->left!=NULL){
//             q.push(make_pair(frontNode->left,d+1));
//         }
//         if(frontNode->right!=NULL){
//             q.push(make_pair(frontNode->right,d));
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<v[i].size();j++){
//             cout<<v[i][j]<<" ";
//             ans.push_back(v[i][j]);
//         }
//         cout<<endl;
//     }
//     return ans;
// }