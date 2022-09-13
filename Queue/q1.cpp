#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<char> q;
    int* freq=new int[256]{0};
    string s;
    cin>>s;
    int len=INT_MIN;
    int idx=-1;
    int size;
    for(int i=0;s[i]!='\0';i++){
        freq[s[i]]+=1;
        if(freq[s[i]]==1){
            q.push(i);
        }else{
            size=q.size();
            if(size>len){
                idx=q.front();
            }
            len=max(len,size);
            while(!q.empty() && s[q.front()]!=s[i]){
                freq[s[q.front()]]=0;
                q.pop();
            }
            if(!q.empty()){
                q.pop();
            }
            q.push(i);
            freq[s[i]]=1;
        }
    }
    size=q.size();
    if(size>len){
        idx=q.front();
    }
    // cout<<size<<endl;
    len=max(len,size);
    cout<<len<<endl;
    for(int i=idx;i<idx+len;i++){
        cout<<s[i];
    }
    return 0;
}
