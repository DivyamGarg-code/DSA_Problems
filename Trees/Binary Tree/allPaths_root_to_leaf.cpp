#include<bits/stdc++.h>
using namespace std;

// Printing all paths from root to leaf node
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


void allPath(Node* root,int &ans,vector<int> v,int temp=0){
    if(root==NULL){
        return;
    }
    v.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
            if(i==0){
                temp=v[i];
            }else{
                temp=temp*10+v[i];
            }
        }
        cout<<endl;
        ans+=temp;
        temp=0;
        v.pop_back();
        return;
    }
    allPath(root->left,ans,v,temp);
    allPath(root->right,ans,v,temp);
}

int sumNumbers(Node* root){
    if(root==NULL){
        return 0;
    }
    int ans=0;
    vector<int> v;
    allPath(root,ans,v);
    return ans;

}
int main(){
    Node* root=buildTree();
    cout<<sumNumbers(root);
    return 0;
}