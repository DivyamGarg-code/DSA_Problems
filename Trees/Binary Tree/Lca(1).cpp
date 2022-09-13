#include<bits/stdc++.h>
using namespace std;

// Lowest Common Ancestor
// Time complexity O(N)
// But this is not a memory efficient approach
// as we are using vectors which takes more space
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

void printNodes(Node* root,int data,vector<Node*> v,vector<Node*> &ans){
    if(root==NULL){
        return;
    }
    v.push_back(root);
    if(root->data==data){
        for(auto x:v){
            ans.push_back(x);
        }
        return;
    }
    if(root->left==NULL && root->right==NULL){
        v.pop_back();
        return;
    }
    printNodes(root->left,data,v,ans);
    printNodes(root->right,data,v,ans);
}

Node* lowestCommonAncestor(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    vector<Node*> v;
    vector<Node*> v1;
    vector<Node*> v2;
    printNodes(root,n1,v,v1);
    // for(auto x:v1){
    //     cout<<x->data<<" ";
    // }
    // cout<<endl;
    printNodes(root,n2,v,v2);
    // for(auto x:v2){
    //     cout<<x->data<<" ";
    // }
    // cout<<endl;
    int k=0;
    int s1=v1.size();
    int s2=v2.size();
    int s=min(s1,s2);
    int i=0;
    Node* ans=NULL;
    while(i<s){
        if(v1[i]==v2[i]){
            ans=v1[i];
            i++;
        }else{
            break;
        }
    }
    return ans;

}
int main(){
    Node* root=buildTree();
    int n1,n2;
    cin>>n1>>n2;
    lowestCommonAncestor(root,n1,n2);
    return 0;
}