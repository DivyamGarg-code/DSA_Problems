#include<bits/stdc++.h>
using namespace std;

/*
    MERGE 2 BST APPROACH-1
    STORE THE INORDER OF BOTH BST IN VECTORS WHICH WILL BE STORED IN SORTED FORM
    MERGE 2 SORTED VECTORS
    CREATE BST FROM THIS SORTED VECTOR
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
};

void insertIntoBST(Node* &root,int data){
    if(root==NULL){
        root=new Node(data);
        return;
    }
    Node* temp=root;
    while(temp!=NULL){
        if(data<=temp->data){
            if(temp->left==NULL){
                Node* n=new Node(data);
                temp->left=n;
                return;
            }else{
                temp=temp->left;
            }
        }else{
            if(temp->right==NULL){
                Node* n=new Node(data);
                temp->right=n;
                return;
            }else{
                temp=temp->right;
            }
        }
    }
}
Node* takeInput(){
    Node* root=NULL;
    int data;
    cin>>data;
    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
    }
    return root;
}
void print(Node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
void inorder(Node* root,vector<int> &v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

vector<int> mergeSortedVectors(vector<int> v1,vector<int> v2){
    vector<int> v;
    int n1=v1.size();
    int n2=v2.size();
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(v1[i]<=v2[j]){
            v.push_back(v1[i]);
            i++;
        }else{
            v.push_back(v2[j]);
            j++;
        }
    }
    while(i<n1){
        v.push_back(v1[i]);
        i++;
    }
    while(j<n2){
        v.push_back(v2[j]);
        j++;
    }
    return v;
}

Node* inorderToBST(int s,int e,vector<int> &v){
    if(s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    Node* root=new Node(v[mid]);
    root->left=inorderToBST(s,mid-1,v);
    root->right=inorderToBST(mid+1,e,v);
    return root;
}
Node* merge2BST(Node* root1,Node* root2){
    vector<int> v1;
    vector<int> v2;
    inorder(root1,v1);
    inorder(root2,v2);
    vector<int> v=mergeSortedVectors(v1,v2);
    // for(auto x:v){
    //     cout<<x<<" ";
    // }
    Node* root=inorderToBST(0,v.size()-1,v);
    return root;

}
int main(){
    Node* root1=takeInput();
    Node* root2=takeInput();
    Node* root=merge2BST(root1,root2);
    print(root);
    return 0;
}