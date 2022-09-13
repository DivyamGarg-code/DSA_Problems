#include<bits/stdc++.h>
using namespace std;
/*

Using Unordered Map

Slightly faster than the Trie Data structure
Ninja developed a love for arrays and strings so this time his teacher gave him an array of strings, ‘A’ of size ‘N’. Each element of this array is a string. The teacher taught Ninja about prefixes in the past, so he wants to test his knowledge.
A string is called a complete string if every prefix of this string is also present in the array ‘A’. Ninja is challenged to find the longest complete string in the array ‘A’.If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None".

Approach : sort the array logic lexographically
logic is let suppose there is a word ninja now check if ninj is present in unordered map if yes then check if ninj:complete string or not according mark m[ninja]=0
and if no then mark m[ninja]=0;
TC O(nlogn)
SC O(n)  
*/
int main(){
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    unordered_map<string,int> map;
    sort(v.begin(),v.end());
    for(auto x:v){
        map[x]=1;
    }
    string ans="";
    int size=0;
    for(int i=0;i<n;i++){
        string s=v[i];
        int j=v[i].size(); // count
        if(j==1){ // it is possibly a good string
            if(j>size){
                ans=s;
                size=j;
            }
        }else{
            s.pop_back();
            if(map.find(s)!=map.end()){
                if(map[s]==1){
                    if(j>size){
                        ans=v[i];
                        size=j;
                    }
                }else{
                    map[v[i]]=0;
                }
                 
            }else{
                map[v[i]]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}

/*
USING TRIE : SLIGHTLY TAKES MORE TIME
 Longest word with with all prefixes
A string is called a complete string if every prefix of this string is also present in the array ‘A’.
Sample Input 1 :
2
6
n ni nin ninj ninja ninga
2
ab bc
Sample Output 1 :
ninja
None

Approach: Iterate through the string if the entire string contains isTerminal=true it means all prefixes of the string also exist :it could be considered as one of the complete string

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
        Trie(){
            root=new TrieNode('\0');
        }
        void insert(string word){
            TrieNode* temp=root;
            for(int i=0;word[i]!='\0';i++){
                int idx=word[i]-'a';
                if(temp->children[idx]==NULL){
                    temp->children[idx]=new TrieNode(word[i]);
                }  
                temp=temp->children[idx];
            }
            temp->isTerminal=true;
        }
        // it will return whether this string is complete string or not
        bool search(string word){ 
            TrieNode* temp=root;
            for(int i=0;word[i]!='\0';i++){
                int idx=word[i]-'a';
                TrieNode* child=temp->children[idx];
                if(child->isTerminal==true){
                    temp=child;
                }else{
                    return false;
                }
            }
            return true;
        }
};


int main(){
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    Trie* t=new Trie();
    int ans=0;
    string result="None";
    for(auto s:v){
        t->insert(s);
    }
    for(auto s:v){
        if(t->search(s)){ // if it is a complete string
            int cnt=s.size();
            if(cnt>ans){
                ans=cnt;
                result=s;
            }else if(cnt==ans){
                if(s<result){
                    result=s;
                }
            }
        }
    }
    cout<<result;
    return 0;
}
*/

