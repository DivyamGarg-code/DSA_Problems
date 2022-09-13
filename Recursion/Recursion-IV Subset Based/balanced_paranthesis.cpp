#include<bits/stdc++.h>
using namespace std;
void solve(string output,int o,int c){
    // base case
    if(o==0 && c==0){
        cout<<output<<endl;
        return;
    }
    if(o==c && o!=0){ // make only 1 choice
        string output1=output;
        output1.push_back('(');
        solve(output1,o-1,c);
    }else if(o<c && o!=0){ // make 2 choices
        string output1=output;
        string output2=output;
        output1.push_back('(');
        output2.push_back(')');
        solve(output1,o-1,c);
        solve(output2,o,c-1);
    }else if(o==0 && c!=0){ // make only 1 choice
        string output1=output;
        output1.push_back(')');
        solve(output1,o,c-1);
    }
}
int main(){
    int n;
    cin>>n;
    string output=""; // output
    int open_bracket=n;
    int close_bracket=n;
    solve(output,open_bracket,close_bracket);
    return 0;
}