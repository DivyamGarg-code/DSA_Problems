#include<bits/stdc++.h>
using namespace std;

/* Number of distinct substrings in a string
 Brute Force 

 unordered_set<string> m;
    string s1;
    cin>>s1;
    int n=s1.size();
    for(int i=0;i<n;i++){
        string s="";
        for(int j=i;j<n;j++){
            s+=s1[j];
            m.insert(s);
        }
    }
    cout<<m.size();

 TC O(n^2) SC O(n^3)
 Must watch
 https://www.geeksforgeeks.org/count-number-of-distinct-substring-in-a-string/
 */

/*
Optimised approach 
https://takeuforward.org/data-structure/number-of-distinct-substrings-in-a-string-using-trie/
Time Complexity: O(n^2), because we have to go through the entire string for all possible different starting points in order to generate all the substrings.

Space Complexity: O(n^2), because in the worst case, all the substrings can be distinct and there will be a node for every substring. Number of substrings of a string of length n is (n * (n + 1) / 2). Hence in the worst case, space complexity will be O(n2).

More optimised but complex code using suffix array TC O(nlogn) SC O(n)
https://www.geeksforgeeks.org/count-distinct-substrings-string-using-suffix-array/
*/
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

class Trie{
    TrieNode* root;
    public:
    int cnt=0;
        Trie(){
            root=new TrieNode('\0');
        }
        void insert(string word){
            TrieNode* temp=root;
            for(int i=0;word[i]!='\0';i++){
                int idx=word[i]-'a';
                if(temp->children[idx]==NULL){
                    temp->children[idx]=new TrieNode(word[i]);
                    cnt+=1;
                }  
                temp=temp->children[idx];
            }
        }
};

int main(){
    Trie* t=new Trie();
    string s1;
    cin>>s1;
    int n=s1.size();
    for(int i=0;i<n;i++){
        string s="";
        for(int j=i;j<n;j++){
            s+=s1[j];
            t->insert(s);
        }
    }
    cout<<t->cnt;
    
    return 0;
}