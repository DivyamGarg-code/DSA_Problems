#include<bits/stdc++.h>
using namespace std;

// Length of Longest Unique Substring
int main(){
    queue<char> q;
    int freq[256]={0};
    string s;
    cin>>s;
    int len=INT_MIN;
    int size;
    for(int i=0;s[i]!='\0';i++){
        freq[s[i]]+=1;
        if(freq[s[i]]==1){
            q.push(s[i]);
        }else{
            size=q.size();
            // cout<<size<<endl;
            len=max(len,size);
            while(!q.empty() && q.front()!=s[i]){
                freq[q.front()]=0;
                q.pop();
            }
            if(!q.empty()){
                q.pop();
            }
            q.push(s[i]);
            freq[s[i]]=1;
        }
    }
    size=q.size();
    // cout<<size<<endl;
    len=max(len,size);
    cout<<len;
    return 0;
}