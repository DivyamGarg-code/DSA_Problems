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

void solve(Node* root,int hd,int lvl,unordered_map<int,unordered_map<int,vector<int>>> &m,int &mini,int &maxi,int &l){
    if(root==NULL){
        return;
    }
    solve(root->left,hd-1,lvl+1,m,mini,maxi,l);
    mini=min(mini,hd);
    maxi=max(maxi,hd);
    l=max(l,lvl);
    m[hd][lvl].push_back(root->data);
    solve(root->right,hd+1,lvl+1,m,mini,maxi,l);
}

void vertiicalOrderPrint(Node* root){
    vector<vector<int>> ans;
    unordered_map<int,unordered_map<int,vector<int>>> m;
    int mini=INT_MAX;
    int maxi=INT_MIN;
    int l=INT_MIN;
    solve(root,0,0,m,mini,maxi,l);
    unordered_map<int,vector<int>> p;
    for(int i=mini;i<=maxi;i++){
        for(int j=0;j<=l;j++){ // m[i] is the map
            // j.first is the level and j.second is the vector
            sort(m[i][j].begin(),m[i][j].end());
            for(auto k:m[i][j]){
                p[i].push_back(k);
            }
        }
    }  
    for(int i=mini;i<=maxi;i++){
        cout<<i<<" -> ";
        for(auto x:p[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    for(int i=mini;i<=maxi;i++){
        vector<int> temp;
        for(auto x:p[i]){
            temp.push_back(x);
        }
        ans.push_back(temp);
    }

}
int main(){
    Node* root=takeInput();
    vertiicalOrderPrint(root);
    return 0;
}



// vector<vector<int>> verticalTraversal(TreeNode* root) {
//         map<int,map<int,vector<int>>> nodes;
//         queue<pair<TreeNode*,pair<int,int>>> q;
//         vector<vector<int>> ans;
//         if(root==NULL){
//             return ans;
//         }
//         q.push(make_pair(root,make_pair(0,0)));
//         while(!q.empty()){
//             pair<TreeNode*,pair<int,int>> temp=q.front();
//             q.pop();
//             TreeNode* frontNode=temp.first;
//             int hd=temp.second.first;
//             int lvl=temp.second.second;
//             nodes[hd][lvl].push_back(frontNode->val); 
//             if(frontNode->left!=NULL){
//                 q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
//             }
//             if(frontNode->right!=NULL){
//                 q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
//             }
//         }
//         map<int,vector<int>> m;
//         for(auto i:nodes){
//             for(auto j:i.second){
//                 // cout<<"("<<i.first<<","<<j.first<<") : ";
//                 sort(j.second.begin(),j.second.end());
//                 for(auto k:j.second){
//                     m[i.first].push_back(k);
//                 }
//                 // cout<<endl;
//             }
//         }
//         for(auto x:m){
//             vector<int> p;
//             for(int i=0;i<x.second.size();i++){
//                 p.push_back(x.second[i]);
//             }
//             ans.push_back(p);
//         }

//         return ans;
//     }
// };