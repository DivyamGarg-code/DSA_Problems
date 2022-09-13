#include<bits/stdc++.h>
using namespace std;

/* vertical traversal of binary tree with printing elements in ascending order which are at same level and same horizontal distance*/
// Important question

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

vector<vector<int>> verticalorderTraversal(Node* root){
    map<int,map<int,vector<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> q;
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<Node*,pair<int,int>> temp=q.front();
        q.pop();
        Node* frontNode=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;
        nodes[hd][lvl].push_back(frontNode->data); 
        if(frontNode->left!=NULL){
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        }
        if(frontNode->right!=NULL){
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
        }
    }
    map<int,vector<int>> m;
    for(auto i:nodes){
        for(auto j:i.second){
            // cout<<"("<<i.first<<","<<j.first<<") : ";
            sort(j.second.begin(),j.second.end());
            for(auto k:j.second){
                m[i.first].push_back(k);
            }
            // cout<<endl;
        }
    }
    for(auto x:m){
        vector<int> p;
        for(int i=0;i<x.second.size();i++){
            p.push_back(x.second[i]);
        }
        ans.push_back(p);
    }
    
    return ans;
}
int main(){
    Node* root=buildTree();
    verticalorderTraversal(root);
}

// for(auto x:v){
//     cout<<x.first<<" : ";
//     for(int i=0;i<x.second.size();i++){
//         cout<<x.second[i]<<" ";
//     }
//     cout<<endl;
// }