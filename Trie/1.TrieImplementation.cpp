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
// -----------------------------------------------------------------------        
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
// -----------------------------------------------------------------------
        bool searchUntil(TrieNode* root,string word){
            // base case
            if(word.length()==0){
                return root->isTerminal;
            }
            // assumption, word will be in the lowercase
            int idx=word[0]-'a';
            TrieNode* child;
            child=root->children[idx];
            if(child==NULL){ // that means the word is not present
                return false;
            }else{ // we will check for next part
                return searchUntil(child,word.substr(1));
            }
        }
        bool searchWord(string word){
            return searchUntil(root,word);
        }
// ------------------------------------------------------------------------
        void remove(TrieNode* root,string word){
            if(word.length()==0){
                if(root->isTerminal==true){ 
                    // that means the word is present so simply mark the terminal as false,so thhat next time it will not be detected
                    root->isTerminal=false;
                    cout<<"This word is removed\n";
                }else{
                    cout<<"This word is not present\n";
                }
                return;
            }
            TrieNode* child;
            int idx=word[0]-'a';
            child=root->children[idx];
            if(child==NULL){
                cout<<"This word is not present\n";
                return;
            }else{
                remove(child,word.substr(1));
            }
        }
        void removeWord(string word){
            remove(root,word);
        }
// -----------------------------------------------------------------------
        bool isPrefix(TrieNode* root,string word){
        if(word.length()==0){
            return true;
        }
        int idx=word[0]-'a';
        TrieNode* child;
        child=root->children[idx];
        if(child==NULL){
            return false;
        }else{
            return isPrefix(child,word.substr(1));
        }
    }/** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return isPrefix(root,prefix);
    }
};

int main(){
    Trie* t=new Trie();
    t->insertWord("time");
    t->insertWord("tis");
    t->insertWord("do");
    t->insertWord("arm");
    t->insertWord("are");
    cout<<t->searchWord("are")<<endl;
    t->removeWord("are");
    cout<<t->searchWord("are");
    return 0;
}



#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char data){
            this->data=data;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};


// class Trie{
//     private:
//         void insertWord(TrieNode* root,string word){
//             if(word.length()==0){
//                 root->isTerminal=true;
//                 return;
//             }
//             TrieNode* child;
//             int idx=word[0]-'a';
//             if(root->children[idx]!=NULL){
//                 child=root->children[idx];
//             }else{
//                 child=new TrieNode(word[0]);
//                 root->children[idx]=child;
//             }
//             return insertWord(child,word.substr(1));
//         }
//         bool searchWord(TrieNode* root,string word){
//             if(word.length()==0){
//                 return root->isTerminal;
//             }
//             TrieNode* child;
//             int idx=word[0]-'a';
//             if(root->children[idx]!=NULL){
//                 child=root->children[idx];
//             }else{
//                 return false;
//             }
//             return searchWord(child,word.substr(1));
//         }

//         void removeWord(TrieNode* root,string word){
//             if(word.length()==0){
//                 if(root->isTerminal){
//                     root->isTerminal=false;
//                     cout<<"Word is removed successfully\n";
//                 }else{
//                     cout<<"Word is not Present\n";
//                 }
//                 return;
//             }
//             TrieNode* child;
//             int idx=word[0]-'a';
//             if(root->children[idx]!=NULL){
//                 child=root->children[idx];
//             }else{
//                 cout<<"The Word dont exist\n";
//             }
//             return removeWord(child,word.substr(1));
//         }
//     public:
//         TrieNode* root;
//         Trie(){
//             root=new TrieNode('\0');
//         }
//         void insert(string word){
//             insertWord(root,word);
//             return;
//         }
//         bool search(string word){
//             return searchWord(root,word);
//         }
//         void remove(string word){
//             removeWord(root,word);
//             return;
//         }

// };
// int main(){
//     Trie* t=new Trie();
//     t->insert("time");
//     t->insert("tis");
//     t->insert("do");
//     t->insert("arm");
//     t->insert("are");
//     cout<<t->search("time")<<endl;
//     cout<<t->search("are")<<endl;
//     cout<<t->search("tis")<<endl;
//     cout<<t->search("do")<<endl;
//     cout<<t->search("don")<<endl;
//     t->remove("are");
//     cout<<t->search("are");
//     return 0;
// }