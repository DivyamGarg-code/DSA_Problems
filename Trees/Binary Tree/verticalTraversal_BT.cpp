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


vector<int> verticalOrder(Node *root){
    map<int,vector<int>> m;
    queue<pair<Node*,int>> q;
    vector<int> ans;
    if(root!=NULL){
        return ans;
    }
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;
        
        m[hd].push_back(frontNode->data);
        
        if(frontNode->left)
        q.push(make_pair(frontNode->left,hd-1));
        if(frontNode->right)
        q.push(make_pair(frontNode->right,hd+1));
    }
    for(auto it: m){
        for(auto i : it.second){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){
    Node* root=buildTree();
    verticalOrder(root);

}

// for(auto x:v){
//     cout<<x.first<<" : ";
//     for(int i=0;i<x.second.size();i++){
//         cout<<x.second[i]<<" ";
//     }
//     cout<<endl;
// }