#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26]; // as there are 26 alphabets that's why 
        bool isTerminal; // it will check the nature of node if true it means it is the last
        TrieNode(char data){
            this->data=data;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};
class Trie{
    public:
        TrieNode* root;
        Trie(){
            root=new TrieNode('\0');
        }
        void insertUntil(TrieNode* root,string word){
            //base case
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }
            // assumption, word will be in the lowercase
            int idx=word[0]-'a';
            TrieNode* child;
            // present
            if(root->children[idx]!=NULL){
                child=root->children[idx];
            }else{ // absent
                child=new TrieNode(word[0]);
                root->children[idx]=child;
            }
            insertUntil(child,word.substr(1));
        }
        void insertWord(string word){
            insertUntil(root,word);
        }
        int childCount(TrieNode* root){
            int sum=0;
            int idx=-1;
            for(int i=0;i<26;i++){
                if(root->children[i]!=NULL){
                    sum+=1;
                    if(sum==1){
                        idx=i;
                    }else if(sum>1){
                        return -1;
                    }
                }
            }
            return idx;

        }
        void prefix(TrieNode* root,string &s){
            int idx=childCount(root);
            if(idx==-1){
                return;
            }else{
                s.push_back(char('a'+idx));
                prefix(root->children[idx],s);
            }
        }
        void solve(string &s){
            prefix(root,s);
            return;
        }
};
string longestCommonPrefix(vector<string> &v, int n){
    string s="";
    // first add all the strings in the the trie
    Trie* t=new Trie();
    for(int i=0;i<n;i++){
        t->insertWord(v[i]);
    }
    t->solve(s);
    return s;    
}
int main(){
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        v.push_back(x);
    }
    cout<<longestCommonPrefix(v,n);
    return 0;
}