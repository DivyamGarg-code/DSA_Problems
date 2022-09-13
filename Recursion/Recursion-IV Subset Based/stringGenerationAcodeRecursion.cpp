#include<bits/stdc++.h>
using namespace std;
int str_to_int(string s){
    int ans=0;
    int k=1;
    for(int i =s.length()-1; i>=0; i--){
        int p=s[i];
        ans+=(p-'0')*k;
        k=k*10;
    }
    return ans;
}
void solve(string s,char ls[],string op,int i=0){
    // base case 
    if(i==s.length()){
        cout<<op<<endl;
        return;
    }
    int idx=s[i]-'0';
    string op1=op; // 1 choice
    op1.push_back(ls[idx]);
    solve(s,ls,op1,i+1);
    if(s[i+1]!='\0'){ // 2nd choice - only work after this condition
        int b=s[i+1]-'0';
        int c=(idx*10)+b;
        if(c<=26){
            string op2=op;
            op2.push_back(ls[c]);
            // s.erase(s.begin()+0,s.begin()+2); // erasing 1st 2 characters(num) from string   
            solve(s,ls,op2,i+2);
        }
    }
    return;
}
int main(){
    string s;
    cin>>s;
    char ls[27];
    ls[0]=' ';
    for(int i = 1; i < 27; i++){
        ls[i]=char(65+i-1);
    }
    string op="";
    solve(s,ls,op);
    return 0;
}