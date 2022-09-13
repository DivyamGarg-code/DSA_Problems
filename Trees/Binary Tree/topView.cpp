#include<bits/stdc++.h>
using namespace std;

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

// vector<int> diagonalTraversal(Node* root){
//     vector<int> ans;
//     if(root==NULL){
//         return ans;
//     }
//     map<int,map<int,vector<int>>> m;
//     queue<pair<Node*,pair<int,int>>> q;
//     q.push(make_pair(root,make_pair(0,0)));
//     while(!q.empty()){
//         pair<Node*,pair<int,int>> temp=q.front();
//         Node* frontNode=temp.first;
//         int hd=temp.second.first;
//         int lvl=temp.second.second;
//         //condition
//         if(frontNode->left!=NULL){
//             q.push(make_pair(frontNode->left)
//         }
//     }

// }

void diagonalTraversal(Node* root){
    vector<int> ans;
    map<int,vector<int>> m;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> temp=q.front();
        q.pop();
        Node* frontNode=temp.first;
        int d=temp.second;
        m[d].push_back(frontNode->data);
        if(frontNode->left!=NULL){
            q.push(make_pair(frontNode->left,d+1));
        }
        if(frontNode->right!=NULL){
            q.push(make_pair(frontNode->right,d));
        }
    }
    for(auto x:m){
        // cout<<x.first<<" : ";
        for(auto i:x.second){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    // for(auto x:m){
    //     ans.push_back(x.second);
    // // } 
    // return ans;
}


int main(){
    Node* root=buildTree();
    diagonalTraversal(root);
}

// for(auto x:v){
//     cout<<x.first<<" : ";
//     for(int i=0;i<x.second.size();i++){
//         cout<<x.second[i]<<" ";
//     }
//     cout<<endl;
// }