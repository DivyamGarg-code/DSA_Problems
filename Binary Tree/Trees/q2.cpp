#include<bits/stdc++.h>
using namespace std;


/*
Creat a Tree having multiple nodes as child nodes 
         1
        / \
       2   3
*/
template<typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode*> children;
        TreeNode(T data){
            this->data=data;
        }
        ~TreeNode(){ // Destructor
            for(int i=0;i<children.size();i++){
                delete children[i];
            }
        } // just calling this destructor all the  tree gets deleted
};

TreeNode<int>* takeInput(){ // will return me the root node
    queue<TreeNode<int>*> q;
    int rootData;
    cout<<"Enter the Root Node\n";
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* temp=q.front();
        int n;
        cout<<"Enter the number of children of "<<temp->data<<" : ";
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            TreeNode<int>* child=new TreeNode<int>(x);
            temp->children.push_back(child);
            q.push(child);
        }
        q.pop();
    }
    
    return root;
}
void printTree(TreeNode<int>* root){
    if(root==NULL){ //this is the edge case
        return;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* temp=q.front();
        cout<<temp->data<<":";
        for(int i=0;i<temp->children.size();i++){
            if(i==temp->children.size()-1){
                cout<<temp->children[i]->data;
                break;
            }
            cout<<temp->children[i]->data<<",";
        }
        cout<<endl;
        for(int i=0;i<temp->children.size();i++){
            q.push(temp->children[i]);
        }
        q.pop();
    }
}

int numNodes(TreeNode<int>* root){ // return the number of nodes
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}

// return the sum of nodes
int sumNodes(TreeNode<int>* root){ // Preorder traversal
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=sumNodes(root->children[i]);
    }
    return sum;
}

// return the maximum node
int maxNode(TreeNode<int>* root){ // Preorder traversal
    if(root==NULL){
        return -1;
    }
    int max_node=root->data;
    for(int i=0;i<root->children.size();i++){
        max_node=max(max_node,maxNode(root->children[i]));
    }
    return max_node;
}

// return the height of tree
int maxHeight(TreeNode<int>* root){ // Preorder traversal
    if(root==NULL){
        return 0;
    }
    int max_h=0;
    for(int i=0;i<root->children.size();i++){
        max_h=max(max_h,maxHeight(root->children[i]));
    }
    return 1+max_h;
}

// printing the nodes at the depth k
void printAtLevelK(TreeNode<int>* root,int k){
    if(root==NULL){ // edge case
        return;
    }
    if(k==0){ // base case
        cout<<root->data<<" ";
    }
    for(int i=0;i<root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
}

int numLeafNodes(TreeNode<int>* root){
    if(root==NULL){ // edge case
        return 0;
    }
    if(root->children.size()==0){ // base case
        return 1;
    }
    int cnt=0;
    for(int i=0;i<root->children.size();i++){
        cnt+=numLeafNodes(root->children[i]);
    }
    return cnt;

}

void preorder(TreeNode<int>* root){ // <left><root><right>
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }

}

void postorder(TreeNode<int>* root){ // <left><right><root>
    if(root==NULL){
        return ;
    }
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}

void deleteTree(TreeNode<int>* root){ // <left><right><root>
    for(int i=0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
} 
// or you can make a destructor to delete the nodes

int main(){
    TreeNode<int>* root=takeInput();
    // printTree(root);
    // cout<<maxHeight(root);
    // printAtLevelK(root,2);
    // cout<<numLeafNodes(root);
    preorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}  