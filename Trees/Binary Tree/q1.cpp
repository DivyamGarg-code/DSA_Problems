#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
    public:
        T data;
        Node* left;
        Node* right;
        Node(T data){
            this->data=data;
            left=NULL;
            right=NULL;
        }
        ~Node(){
            delete left;
            delete right;
        }
};

Node<int>* takeInput(){
    int rootData;
    cout<<"Enter the data\n";
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    Node<int>* root=new Node<int>(rootData);
    Node<int>* leftChild=takeInput();
    Node<int>* rightChild=takeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;

}

Node<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter the root data\n";
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    Node<int>* root=new Node<int>(rootData);
    queue<Node<int>*> q;
    q.push(root);
    while(!q.empty()){
        Node<int>* temp=q.front();
        // cout<<"Enter the child nodes of "<<temp->data<<" : ";
        int l,r;
        cin>>l>>r;
        if(l!=-1){
            Node<int>* leftChild=new Node<int>(l);
            temp->left=leftChild;
            q.push(temp->left);
        }
        if(r!=-1){
            Node<int>* rightChild=new Node<int>(r);
            temp->right=rightChild;
            q.push(temp->right);
        }
        q.pop();
    }
    return root;
}
void printTree(Node<int>* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data<<" ";
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);

}

void printTreeLevelWise(Node<int>* root){
    if(root==NULL){
        return;
    }
    queue<Node<int>*> q;
    q.push(root);
    while(!q.empty()){
        Node<int>* temp=q.front();
        cout<<temp->data<<":";
        if(temp->left!=NULL){
            cout<<"L:"<<temp->left->data<<",";
            q.push(temp->left);
        }else{
            cout<<"L:"<<-1<<",";
        }
        if(temp->right!=NULL){
            cout<<"R:"<<temp->right->data;
            q.push(temp->right);
        }else{
            cout<<"R:"<<-1;
        }
        cout<<endl;
        q.pop();
    }
}

void printLevelATNewLine(Node<int> *root) {
    queue<Node<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node<int> *temp = q.front();
        q.pop();
        if (temp == NULL) { // Null act as a seperator
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << temp->data << " ";
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

void numLeafNodes(Node<int>* root,int &cnt){ // Time complexity,Space Complexity O(n)
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right==NULL){
        cnt+=1;
    }
    numLeafNodes(root->left,cnt);
    numLeafNodes(root->right,cnt);
}
int cntLeafNodes(Node<int>* root){
    int cnt=0;
    numLeafNodes(root,cnt);
    return cnt;
}

int numNodes(Node<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+numNodes(root->left)+numNodes(root->right);
}

bool isPresent(Node<int>* root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(isPresent(root->left,x) || isPresent(root->right,x)){
        return true;
    }
    return false;
}

int height(Node<int>* root){ // Time complexity O(n) Space complexity O(height) ->which is the max height 
                            // from root to leaf
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}


void mirror(Node<int>* root) {
    // Write your code here
    if (root == NULL)  
        return;  
    mirror(root->left); 
    mirror(root->right); 
    swap(root->left,root->right);
}

void inorder(Node<int>* root){ // <left><root><right>
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node<int>* root){ // <root><left><right>
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node<int>* root){ // <left><right><root>
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

Node<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    if(preLength <= 0 ){
        return NULL;
    }
    int rootData = preorder[0];
    int newprelen = 0;
    while(inorder[newprelen] != rootData){
        newprelen++;
    }

    Node<int> * left = buildTree(preorder + 1, newprelen, inorder, newprelen);
    Node<int> * right = buildTree(preorder + newprelen + 1, preLength - newprelen - 1 ,inorder + newprelen + 1, preLength - newprelen - 1);
    Node<int> * root = new Node<int> (rootData);
    root->left = left;
    root->right = right;
    return root;
} 
int main(){
    // Node<int>* root=new Node<int>(1);
    // Node<int>* node1=new Node<int>(2);
    // Node<int>* node2=new Node<int>(3);
    // root->left=node1;
    // root->right=node2;
    // printTree(root);
    // delete root;
    Node<int>* root=takeInputLevelWise();
    // printTreeLevelWise(root);
    inorder(root);
    cout<<endl;

    return 0;
}