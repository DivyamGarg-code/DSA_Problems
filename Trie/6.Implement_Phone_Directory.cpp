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
    private:
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
    public:
        TrieNode* root;
        Trie(){
            root=new TrieNode('\0');
        }
        
        void insertWord(string word){
            insertUntil(root,word);
        }
        void printSuggesstions(TrieNode* curr,vector<string> &temp,string prefix){
            if(curr->isTerminal==true){
                temp.push_back(prefix);
            }
            for(char i='a';i<='z';i++){
                TrieNode* next=curr->children[i-'a'];
                if(next!=NULL){
                    prefix.push_back(i);
                    printSuggesstions(next,temp,prefix);
                    prefix.pop_back();
                }
            }
        }
        vector<vector<string>> getSuggestions(string s){
            TrieNode* prev=root;
            string prefix="";
            vector<vector<string>> output;
            for(int i=0;i<s.length();i++){
                prefix.push_back(s[i]);
                TrieNode* curr=prev->children[s[i]-'a'];
                if(curr==NULL){ // that means there are no further recoomendations
                    break;
                }
                vector<string> temp;
                printSuggesstions(curr,temp,prefix);
                output.push_back(temp);
                temp.clear();
                prev=curr;

            }
            return output;
        }
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr){
    // creation of trie
    Trie* t=new Trie();

    // insert all the strings in the trie
    for(int i=0;i<contactList.size();i++){
        string str=contactList[i];
        t->insertWord(str);
    }
    
    return t->getSuggestions(queryStr);
}
int main(){
    vector<string> contactList;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        contactList.push_back(x);
    }
    string query;
    cin>>query;
    vector<vector<string>> v;
    v=phoneDirectory(contactList,query);
    for(auto x:v){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}