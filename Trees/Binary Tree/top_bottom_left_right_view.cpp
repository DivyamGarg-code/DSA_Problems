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

vector<int> topView(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    map<int,int> m;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> temp=q.front();
        q.pop();
        Node* frontNode=temp.first;
        int hd=temp.second;
        if(m.count(hd)==0){
            m[hd]=frontNode->data;
        }
         if(frontNode->left!=NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right!=NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    for(auto x:m){
        ans.push_back(x.second);
    } 
    return ans;
}

vector<int> bottomView(Node* root){
    vector<int> ans;
    map<int,int> m;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> temp=q.front();
        q.pop();
        Node* frontNode=temp.first;
        int hd=temp.second;
        m[hd]=frontNode->data;
        if(frontNode->left!=NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right!=NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    // for(auto x:m){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    for(auto x:m){
        ans.push_back(x.second);
    } 
    return ans;
}

void solve(Node* root,vector<int> &ans,int lvl){
    // base case
    if(root==NULL){
        return;
    }
    if(lvl==ans.size()){
        ans.push_back(root->data);
    }
    solve(root->left,ans,lvl+1);
    solve(root->right,ans,lvl+1);
}
vector<int> leftView(Node* root){
    vector<int> ans;
    solve(root,ans,0);
    for(auto x:ans){
        cout<<x<<" ";
    } 
    return ans;
}

void solve_rt(Node* root,vector<int> &ans,int lvl){
    // base case
    if(root==NULL){
        return;
    }
    if(lvl==ans.size()){
        ans.push_back(root->data);
    }
    solve_rt(root->right,ans,lvl+1);
    solve_rt(root->left,ans,lvl+1);
}
vector<int> rightView(Node* root){
    vector<int> ans;
    solve(root,ans,0);
    for(auto x:ans){
        cout<<x<<" ";
    } 
    return ans;
}


int main(){
    Node* root=buildTree();
    leftView(root);

}

// for(auto x:v){
//     cout<<x.first<<" : ";
//     for(int i=0;i<x.second.size();i++){
//         cout<<x.second[i]<<" ";
//     }
//     cout<<endl;
// }