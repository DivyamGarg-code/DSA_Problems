#include<bits/stdc++.h>
using namespace std;

bool valid(string a){
    stack<char> s;
    for(int i=0;a[i]!='\0';i++){
        if(a[i]=='('){
            s.push('(');
        }else if(a[i]=='['){
            s.push('[');
        }else if(a[i]=='{'){
            s.push('{');
        }else if(a[i]==')'){
            if(s.empty() || s.top()!='('){
                return false; 
            }else{
               s.pop(); 
            }
        }else if(a[i]==']'){
            if(s.empty() || s.top()!='['){
                return false; 
            }else{
               s.pop(); 
            }
        }else if(a[i]=='}'){
            if(s.empty() || s.top()!='{'){
                return false; 
            }else{
               s.pop(); 
            }
        }
    }
    return s.empty();
}
int main(){
    string a;
    cin>>a;
    if(valid(a)){
        cout<<"Valid\n";
    }else{
        cout<<"Invalid\n";
    }
    return 0;
}