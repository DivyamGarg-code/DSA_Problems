#include<bits/stdc++.h>
using namespace std;

// First non repeating character problem

int main(){
    queue<char> q;
    int freq[26]={0};
    char ch;
    cin>>ch;
    while(ch!='.'){ // Running stream of characters
        int i=ch-97;
        freq[i]+=1;
        if(q.empty()){
            if(freq[i]==1){
                q.push(q.front());
                cout<<ch<<endl;
            }else{
                cout<<-1<<endl;
            }
        }else{
            int f=q.front()-97;
            if(freq[f]==1){
                q.push(ch);
                cout<<q.front()<<endl;
            }else{
                while(freq[f]!=1){
                    q.pop();
                    if(q.empty()){
                        break;
                    }
                    f=q.front()-97;
                }
                if(q.empty()){
                    cout<<-1<<endl;
                }else{
                    cout<<q.front()<<endl;
                }
            }
        }
        cin>>ch;
    }
    return 0;
}