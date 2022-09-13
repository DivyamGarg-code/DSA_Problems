#include<bits/stdc++.h>
using namespace std;


/*
Creat a Tree having multiple nodes as child nodes 
         1
        / \
       2   3
       PREORDER TRAVERSAL
*/
template<typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode*> children;
        TreeNode(T data){
            this->data=data;
        }
};

TreeNode<int>* takeInput(){ // will return me the root node
    int rootData;
    cout<<"Enter the data\n";
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    int n;
    cout<<"Enter the number of children of "<<rootData<<" ";
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child=takeInput();
        // Now I've to connect this child to the rootNode;
        root->children.push_back(child);
    }
    return root;
}
void printTree(TreeNode<int>* root){
    if(root==NULL){ //this is the edge case
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



int maxNode(TreeNode<int>* root){ // Preorder traversal
    if(root==NULL){
        return NULL;
    }
    int max_node=root->data;
    for(int i=0;i<root->children.size();i++){
        max_node=max(max_node,maxNode(root->children[i]));
    }
    return max_node;
}
int main(){
    // TreeNode<int>* root=new TreeNode<int>(1);
    // TreeNode<int>* node1=new TreeNode<int>(2);
    // TreeNode<int>* node2=new TreeNode<int>(3);
    // TreeNode<int>* node3=new TreeNode<int>(4);
    // TreeNode<int>* node4=new TreeNode<int>(5);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // root->children[0]->children.push_back(node3);
    // root->children[0]->children.push_back(node4);
    TreeNode<int>* root=takeInput();
    printTree(root);
    return 0;
} 