#include<bits/stdc++.h>
using namespace std;
void solve(string s,char keypad[10][10],string op){
    if(s.length()==0){
        cout<<op<<" ";
        return;
    }
    int idx=s[0]-'0';
    if((idx>=2 && idx<=6) || (idx==8)){ // 3 calls
        string op1=op;
        string op2=op;
        string op3=op;
        op1.push_back(keypad[idx][0]);
        op2.push_back(keypad[idx][1]);
        op3.push_back(keypad[idx][2]);
        s.erase(s.begin()+0);
        solve(s,keypad,op1);
        solve(s,keypad,op2);
        solve(s,keypad,op3);
    }else if(idx==7 || idx==9){ // 4 calls
        string op1=op;
        string op2=op;
        string op3=op;
        string op4=op;
        op1.push_back(keypad[idx][0]);
        op2.push_back(keypad[idx][1]);
        op3.push_back(keypad[idx][2]);
        op4.push_back(keypad[idx][3]);
        s.erase(s.begin()+0);
        solve(s,keypad,op1);
        solve(s,keypad,op2);
        solve(s,keypad,op3);
        solve(s,keypad,op4);
    }else{ // for  case 0 and 1
        s.erase(s.begin()+0);
        solve(s,keypad,op);
    }

}
int main(){
    char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
    // for(int i =0;keypad[2][i]!='\0'; i++){
    //     cout<<keypad[2][i]<<" ";
    // }
    string s;
    cin>>s;
    string op="";
    solve(s,keypad,op);
    return 0;
}