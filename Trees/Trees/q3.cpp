#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode*> children;
        TreeNode(T data){
            this->data=data;
        }
        ~TreeNode(){
            for(int i=0;i<children.size();i++){
                delete children[i];
            }
        }
};

void printTree(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

TreeNode<int>* takeInput(){
    int rootdata;
    // cout<<"Enter the root data : ";
    cin>>rootdata;
    TreeNode<int>* root=new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* temp=q.front();
        // cout<<"Enter the number of children of "<<temp->data<<" : ";
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            TreeNode<int>* child=new TreeNode<int>(x);
            q.push(child);
            temp->children.push_back(child);
        }
        q.pop();
    }
    return root;
}

// TreeNode<int>* nextLargerElement(TreeNode<int>* root,int n){

//     TreeNode<int>* ans=NULL;
//     if(root->data>n){
//         ans=root;
//     }
//     for(int i=0;i<root->children.size();i++){
//         TreeNode<int>* temp=nextLargerElement(root->children[i],n);
//         if(temp!=NULL && ans==NULL){
//             ans=temp;
//         }else if(temp!=NULL && ans!=NULL && temp->data<ans->data){
//             ans=temp;
//         }
//     }
//     return ans;
// }

void replaceWithDepthValue(TreeNode<int> *root,int d=0){    
    if(root==NULL){
        return;
    }
    root->data=d;
    for(int i=0;i<root->children.size();i++){
        replaceWithDepthValue(root->children[i],d+1);
    }
}
void printLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*> q;
    if(root==NULL){
        return;
    }
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode<int>* temp=q.front();
        q.pop();
        if(temp==NULL){
            if(q.empty()){
                break;
            }else{
                cout<<endl;
                q.push(NULL);
                continue;
            }
        }
        cout<<temp->data<<" ";
        for(int i=0;i<temp->children.size();i++){
            q.push(temp->children[i]);
        }
    }

}

// void helper(TreeNode<int>* root,TreeNode<int>* &node,int &maxSum){
//     int currSum=root->data;
//     for(int i=0;i<root->children.size();i++){
//         currSum+=root->children[i]->data;
//         helper(root->children[i],node,maxSum);
//     }
//     if(currSum>maxSum){
//         maxSum=currSum;
//         node=root;
//     }
// }
// TreeNode<int>* maxSumNode(TreeNode<int> *root){
//     if(root==NULL){
//         return NULL;
//     }
//     TreeNode<int>* node;
//     int maxSum=0;
//     helper(root,node,maxSum);
//     return node;

// }
void helper(TreeNode<int> *root,TreeNode<int>* &node,int n){
    int temp=root->data;
    if(temp>n){
        if(node==NULL || temp<node->data){
            node=root;
        }
    }
    for(int i=0;i<root->children.size();i++){
        helper(root->children[i],node,n);
    }
}
TreeNode<int>* nextLargerElement(TreeNode<int> *root,int n){
    TreeNode<int>* node=NULL;
    helper(root,node,n);
    return node;

}



int main(){
    TreeNode<int>* root=takeInput();
    // replaceWithDepthValue(root);
    // printLevelWise(root);
    TreeNode<int>* node=nextLargerElement(root,130);
    cout<<node->data;
    return 0;
}