#include<bits/stdc++.h>
using namespace std;

// Rearrange characters 
// USING MAX HEAP
/*
Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

TIME COMPLEXITY O(NLOGN)
SPACE COMPLEXITY O(SIZE OF THE STRING)
*/
class Pair{
    public:
        char ch;
        int freq;
        Pair(char c,int x){
            ch=c;
            freq=x;
        }
};

class compare{
    public:
        bool operator()(Pair* a,Pair* b){
            return a->freq<b->freq;
        }
};
int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    int freq=0;
    priority_queue<Pair*,vector<Pair*>,compare> maxHeap;
    char ch;
    for(int i=0;i<s.size();i++){
        if(i==0){
            ch=s[i];
            freq+=1;
        }else{
            if(s[i]==ch){
                freq+=1;
            }else{
                Pair* p=new Pair(ch,freq);
                maxHeap.push(p);
                ch=s[i]; // update the character
                freq=1; // update the frequency of that character
            }
        }
    }
    Pair* p=new Pair(ch,freq);
    maxHeap.push(p);
    int i=0;
    int k=0;
    Pair* prev;
    Pair* curr;
    while(!maxHeap.empty()){
        if(k==0){
            prev=maxHeap.top();
            maxHeap.pop();
            s[i]=prev->ch;
            prev->freq-=1;
            i++;
            k=1;
        }else{
            curr=maxHeap.top();
            maxHeap.pop();
            s[i]=curr->ch;
            curr->freq-=1;
            if(prev->freq!=0){
                maxHeap.push(prev);
            }
            prev=curr;
            i++;
        }
    }
    if(i==s.size()){
        for(int i=0;i<s.size();i++){
            cout<<s[i];
        }
    }else{
        cout<<"Not Possible\n";
    }
    return 0;
}