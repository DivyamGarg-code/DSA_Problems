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

Node* solve(vector<int> &v, int mini,int maxi,int &i){
    if(i>=v.size()){
        return NULL;
    }
    if(v[i]<mini || v[i]>maxi){
        return NULL;
    }
    Node* root=new Node(v[i++]);
    root->left=solve(v,mini,root->data,i);
    root->right=solve(v,root->data,maxi,i);
    return root;

}
Node* createBST(vector<int> &pre){
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=0;
    Node* root=solve(pre,mini,maxi,i);
    return root;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    Node* root=createBST(v);
    print(root);
}