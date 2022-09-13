#include<bits/stdc++.h>
using namespace std;

// Vertical Order Print of Binary Tree using Map STL
// TC O(N) SC O(N)
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

Node* takeInput(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* root=new Node(data);
    Node* left=takeInput();
    Node* right=takeInput();
    root->left=left;
    root->right=right;
    return root;
}

void solve(Node* root,int hd,unordered_map<int,vector<int>> &m,int &mini,int &maxi){
    if(root==NULL){
        return;
    }
    solve(root->left,hd-1,m,mini,maxi);
    mini=min(mini,hd);
    maxi=max(maxi,hd);
    m[hd].push_back(root->data);
    solve(root->right,hd+1,m,mini,maxi);
}

void vertiicalOrderPrint(Node* root){
    unordered_map<int,vector<int>> m;
    int mini=INT_MAX;
    int maxi=INT_MIN;
    solve(root,0,m,mini,maxi);
    for(int i=mini;i<=maxi;i++){
        cout<<i<<" -> ";
        for(auto x:m[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int main(){
    Node* root=takeInput();
    vertiicalOrderPrint(root);
    return 0;
}