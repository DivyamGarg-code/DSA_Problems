#include<bits/stdc++.h>
using namespace std;
class Node{ // Here no need to create data as we can assume ->
    public:
        Node* left;  // means 0
        Node* right; // means 1
        
};

class Trie{
    Node* root;
    public:
        Trie(){
            root=new Node();
        }
        void insert(int n,int max_bits){ // this will insert a number
            Node* temp=root;
            for(int i=max_bits-1;i>=0;i--){
                int bit=(n&(1<<i)); // give you the i_th bit
                if(bit==0){
                    if(temp->left==NULL){
                        temp->left=new Node();
                    }
                    temp=temp->left;
                }else{
                    if(temp->right==NULL){
                        temp->right=new Node();
                    }
                    temp=temp->right;
                }
            }
        }
        // helper function to find the maximum xor
        int max_xor_helper(int value,int max_bits){
            Node* temp=root;
            int current_ans=0; // directly find the answer
            for(int i=max_bits-1;i>=0;i--){
                int bit=value&(1<<i); // give you the i_th bit
                if(bit==0){ // check for its complementary
                    if(temp->right!=NULL){
                        current_ans+=(1<<i);
                        temp=temp->right;
                    }else{
                        temp=temp->left;
                    }
                
                }else{
                    if(temp->left!=NULL){ // if its complementry is present
                        temp=temp->left;
                        current_ans+=(1<<i);
                    }else{
                        temp=temp->right;
                    }
                    
                }
            }
            return current_ans;
        }
        int max_xor(int b[],int n,int &max_bits){
            int max_xor=0;
            for(int i=0;i<n;i++){
                int value=b[i];
                insert(value,max_bits);
                int curr_xor=max_xor_helper(value,max_bits);
                max_xor=max(max_xor,curr_xor);
            }
            return max_xor;
        }
};
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[n];
    b[0]=a[0];
    for(int i=1;i<n;i++){
        b[i]=b[i-1]^a[i];
    }
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    int maxi=b[0];
    for(int i=1;i<n;i++){
        maxi=max(maxi,b[i]);
    }
    int max_bits=log(maxi)/log(2)+1;
    Trie* t=new Trie();
    // Why taken the maximum because this maxi will contain the xor of all the subaarays starting from idx=0 to idx=i
    cout<<max(maxi,t->max_xor(b,n,max_bits));
    return 0;
}