#include<bits/stdc++.h>
using namespace std;

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
                cnt=0;
            }
        }
};
class Trie{
        TrieNode* root;
    public:

    Trie(){
        root=new TrieNode('\0');
    }

    void insert(string word){
        TrieNode* temp=root;
        for(int i=0;word[i]!='\0';i++){
            int idx=word[i]-'a';
            TrieNode* child;
            if(temp->children[idx]==NULL){
                child=new TrieNode(word[i]);
                temp->children[idx]=child;
            }else{
                child=temp->children[idx];
            }
            child->cnt+=1;
            temp=child;
        }
        temp->isTerminal=true;
    }
    bool search(string word){
        int len=word.length();
        TrieNode* temp=root;
        for(int i=0;i<len;i++){
            int idx=word[i]-'a';
            if(temp->children[idx]==NULL){
                return false;
            }else{
                temp=temp->children[idx];
                cout<<temp->data<<" "<<temp->cnt<<endl;
            }
        }
        return temp->isTerminal;
    }
    int countWordsEqualTo(string word){
        TrieNode* temp=root;
        for(int i=0;word[i]!='\0';i++){
            int idx=word[i]-'a';
            TrieNode* child=temp->children[idx];
            if(child==NULL  || child->cnt==0){
                return 0;
            }
            temp=child;
            // cout<<temp->data<<" "<<temp->cnt<<endl;
        }
        if(temp->isTerminal){
            return temp->cnt;
        }
        return 0;
    }

    int countWordsStartingWith(string word){
        TrieNode* temp=root;
        for(int i=0;word[i]!='\0';i++){
            int idx=word[i]-'a';
            TrieNode* child=temp->children[idx];
            if(child==NULL || child->cnt==0){
                return 0;
            }
            // cout<<child->data<<" "<<child->cnt<<endl;
            temp=child;
        }
        return temp->cnt;
    }

    void erase(string word){
        TrieNode* temp=root;
        for(int i=0;word[i]!='\0';i++){
            int idx=word[i]-'a';
            TrieNode* child;
            if(temp->children[idx]==NULL){
                return;
            }else{
                temp=temp->children[idx];
            }
            temp->cnt-=1;
        }
        if(temp->cnt==0){ // total distiction of word
            temp->isTerminal=false;
        }
    }
};
int main(){
    Trie* t=new Trie();
    t->insert("samsung");
    t->insert("samsung");
    t->insert("vivo");
    t->erase("samsung");
    cout<<t->countWordsStartingWith("samsung")<<endl;
    cout<<t->countWordsStartingWith("vivo")<<endl;
    return 0;
}