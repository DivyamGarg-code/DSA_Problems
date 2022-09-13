#include<bits/stdc++.h>
using namespace std;

/*
Minimum Time to Burn a Tree
TIME COMPLEXITY O(NLOGN)
SPACE COMPLEXITY O(N)
Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
*/
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

void print(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);

}
void nodeToParent(Node* root,int target,Node* &targetNode,map<Node*,Node*> &m){
    Node* n=NULL;
    m.insert(make_pair(root,n));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp->data==target){
            targetNode=temp;
        }
        if(temp->left!=NULL){
            q.push(temp->left);
            m.insert(make_pair(temp->left,temp)); 
        }
        if(temp->right!=NULL){
            q.push(temp->right);
            m.insert(make_pair(temp->right,temp)); 
        }
    }
}

int minTime(Node* root, int target) {
    // step1:Create node to parent mapping
    // step2:find the target node
    // step3:burn the tree in minimum time
    Node* targetNode=NULL;
    map<Node*,Node*> m;
    nodeToParent(root,target,targetNode,m);
    int time=0;
    map<Node*,bool> visited;
    queue<Node*> q;
    q.push(targetNode);
    visited[targetNode]=true;
    while(!q.empty()){
        bool flag=0;
        int size=q.size();
        for(int i=0;i<size;i++){ 
            Node* temp=q.front();
            Node* parentNode=m[temp];
            q.pop();
            // left child
            if(temp->left!=NULL){
                if(visited.count(temp->left)==0){ // that means this node is unvisited
                    flag=1;
                    cout<<temp->left->data<<" ";
                    q.push(temp->left); 
                    visited[temp->left]=true;
                }
            }
            // right child
            if(temp->right!=NULL){
                if(visited.count(temp->right)==0){ // that means this node is unvisited
                    flag=1;
                    cout<<temp->right->data<<" ";
                    q.push(temp->right); 
                    visited[temp->right]=true;
                }
            }
            // parent
            if(parentNode!=NULL){
                if(visited.count(parentNode)==0){ // that means this node is unvisited
                    flag=1;
                    q.push(parentNode); 
                    visited[parentNode]=true;
                }
            }
        }
        if(flag==1){
            time++;
        }
    }
    return time;
}

int main(){
    Node* root=buildTree();
    cout<<minTime(root,10);
    return 0;
}