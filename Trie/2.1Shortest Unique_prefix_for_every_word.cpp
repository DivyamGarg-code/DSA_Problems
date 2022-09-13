#include<bits/stdc++.h>
using namespace std;
/*
Shortest Unique prefix for every word

Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another.

Expected Time Complexity: O(N*length of each word)
Expected Auxiliary Space: O(N*length of each word)

Example 1:

Input: 
N = 4
arr[] = {"zebra", "dog", "duck", "dove"}
Output: z dog du dov
Explanation: 
z => zebra 
dog => dog 
duck => du 
dove => dov 

m->length of eachh string
n->lenght of each string
TC O(m*n)
SC O(m*n)
*/
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int cnt;
        TrieNode(char data){
            this->data=data;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            cnt=0;
            isTerminal=false;
        }
};

class Trie{
    private:
        TrieNode* root;
        void insertWord(TrieNode* root,string word){
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }
            TrieNode* child;
            int idx=word[0]-'a';
            if(root->children[idx]!=NULL){
                child=root->children[idx];
            }else{
                child=new TrieNode(word[0]);
                root->children[idx]=child;
            }
            child->cnt+=1;
            return insertWord(child,word.substr(1));
        }
        
    public:
        Trie(){
            root=new TrieNode('\0');
        }
        void insert(string word){
            insertWord(root,word);
            return;
        }   

        string search(string word){
            TrieNode* temp=root;
            string s="";
            for(int i=0;word[i]!='\0';i++){
                int idx=word[i]-'a';
                TrieNode* child=temp->children[idx];
                s.push_back(child->data);
                if(child->cnt==1){
                    return s;
                }
            //    cout<<child->data<<" -> "<<child->cnt<<endl;
                temp=child;
            }
            return s;
        }

};

vector<string> findPrefixes(vector<string> &v,int n){
    vector<string> ans;
    Trie* t=new Trie(); 
    for(auto s:v){
        t->insert(s);
    } 
    for(auto s:v){
        ans.push_back(t->search(s));
    } 
    return ans;
}
int main(){
    vector<string> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        v.push_back(x);
    }
    vector<string> ans=findPrefixes(v,n);
    for(auto x:ans){
        cout<<x<<endl;
    }
    // Trie* t=new Trie();
    // t->insert("coding");
    // t->insert("coddint");
    // t->insert("code");
    // t->insert("coly");
    // t->search("coding");
    return 0;
}