#include<bits/stdc++.h>
using namespace std;

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

// using vectors
// TC O(N)  SC O(N)
void solve(Node* root,vector<int> &v,int k,int &i){
    if(root==NULL){
        return;
    }
    solve(root->left,v,k,i);
    v.push_back(root->data);
    if(root->data==k){
        i=v.size()-1;
    }
    solve(root->right,v,k,i);

}
pair<int,int> predecessorSuccessor(Node* root, int key){
    pair<int,int> p;
    vector<int> v;
    int idx=-1;
    solve(root,v,key,idx);
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl<<idx;
    if(idx==-1 || (v.size()==1 && idx==0)){
        p=make_pair(-1,-1);
        return p;
    }else if(idx==0){
        p=make_pair(-1,v[idx+1]);
        return p;
    }else if(idx==v.size()-1){
        p=make_pair(v[idx-1],-1);
        return p;
    }else{
        p=make_pair(v[idx-1],v[idx+1]);
        return p;
    }

}

// More optimized
// TC O(n) SC O(1)
pair<int,int> pre_succ(Node* root,int key){
    // find the key
    int pred=-1;
    int succ=-1;
    Node* temp=root;
    while(temp->data!=key){
        if(key<temp->data){
            succ=temp->data;
            temp=temp->left;
        }else if(key>temp->data){
            pred=temp->data;
            temp=temp->right;
        }
    }

    // pred
    Node* leftSubtree=temp->left;
    while(leftSubtree!=NULL){
        pred=leftSubtree->data;
        leftSubtree=leftSubtree->right;
    }

    // succ
    Node* rightSubtree=temp->right;
    while(rightSubtree!=NULL){
        succ=rightSubtree->data;
        rightSubtree=rightSubtree->left;
    }

    return {pred,succ};
}


int main(){
    Node* root=NULL;
    takeInput(root);
    int k;
    cin>>k;
    predecessorSuccessor(root,k);
    return 0;
}