#include<bits/stdc++.h>
using namespace std;

// Maximum XOR Problem
// Find a pair with maximum XOR
/*
input[]={3,10,5,25,2,8}
output=5^25=28 maximum
steps:
* 1st calculate the maximum number find its number of bits
* SEE CODE BLOCKS VIDEO

TIME COMPLEXITY O(N*LOG(N))
SPACE COMPLEXITY O(N)

*/
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
        int max_xor(int a[],int n,int &max_bits){
            int max_xor=0;
            for(int i=0;i<n;i++){
                int value=a[i];
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
    int maxi=a[0];
    for(int i=1;i<n;i++){
        maxi=max(maxi,a[i]);
    }
    int max_bits=log(maxi)/log(2)+1;
    cout<<max_bits<<endl;
    Trie* t=new Trie();
    cout<<t->max_xor(a,n,max_bits);
    return 0;
}





// Maximum XOR Problem
// Find a pair with maximum XOR
/*
input[]={3,10,5,25,2,8}
output=5^25=28 maximum
steps:
* 1st calculate the maximum number find its number of bits
* initialise list of n strings with max_bits*"0"
then update the values of string to get the correct bits of n numbers
* After that insert the strings in the trie now check for each number in the array
whose bits you already have match it withh best possible combination from the trie
that fits the number

TIME COMPLEXITY O(N*LOG(N))
SPACE COMPLEXITY O(MAX_BITS^2)

*/


// class TrieNode{
//     public:
//         char data;
//         TrieNode* children[2]; // as there are 2 alphabets that's why 
//         bool isTerminal; // it will check the nature of node if true it means it is the last
//         TrieNode(char data){
//             this->data=data;
//             for(int i=0;i<2;i++){
//                 children[i]=NULL;
//             }
//             isTerminal=false;
//         }
// };
// class Trie{
//     private:
//         void insertUntil(TrieNode* root,string word){
//             //base case
//             if(word.length()==0){
//                 root->isTerminal=true;
//                 return;
//             }
//             // assumption, word will be in the lowercase
//             int idx=word[0]-'0';
//             TrieNode* child;
//             // present
//             if(root->children[idx]!=NULL){
//                 child=root->children[idx];
//             }else{ // absent
//                 child=new TrieNode(word[0]);
//                 root->children[idx]=child;
//             }
//             insertUntil(child,word.substr(1));
//         }
//         void solveNum(TrieNode* root,string word,int &y,int j){
//             if(word.length()==0){
//                 return;
//             }
//             TrieNode* child;
//             if(word[0]=='0'){
//                 if(root->children[1]!=NULL){
//                     child=root->children[1];
//                 }else{
//                     child=root->children[0];
//                 }
//             }else{ // if bit is 1
//                 if(root->children[0]!=NULL){
//                     child=root->children[0];
//                 }else{
//                     child=root->children[1];
//                 }
//             }
//             if(child->data=='1'){
//                 y+=pow(2,j);
//             }
//             j-=1;
//             return solveNum(child,word.substr(1),y,j);

//         }
//     public:
//         TrieNode* root;
//         Trie(){
//             root=new TrieNode('\0');
//         }
        
//         void insertWord(string word){
//             insertUntil(root,word);
//         }

//         int solve(string word,int i,int a[],int max_bits){
//             int j=max_bits-1;
//             int x=a[i];
//             int y=0;
//             solveNum(root,word,y,j);
//             return x^y;
//         }

// };


// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int maxi=a[0];
//     for(int i=1;i<n;i++){
//         maxi=max(maxi,a[i]);
//     }
//     int max_bits=log(maxi)/log(2)+1;
//     cout<<max_bits<<endl;
//     string* l=new string[n];
//     string s(max_bits,'0');
//     for(int i=0;i<n;i++){
//         l[i]=s;
//     }

//     for(int i=0;i<n;i++){
//         int j=max_bits-1;
//         int num=a[i];
//         while(num>0){
//             if(num&1){
//                 l[i][j]='1';
//             }else{
//                 l[i][j]='0';
//             }
//             j--;
//             num=num>>1;
//         }
//     }
//     int ans=INT_MIN;
//     Trie* t=new Trie();
//     for(int i=0;i<n;i++){
//         t->insertWord(l[i]);
//     }
//     for(int i=0;i<n;i++){
//         int num=t->solve(l[i],i,a,max_bits);
//         ans=max(ans,num);
//     }
//     cout<<ans;
//     return 0;

// }