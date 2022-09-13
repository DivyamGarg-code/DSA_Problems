#include<bits/stdc++.h>
using namespace std;

// Permutation with case change

void solve(string in,string out){
    // base case
    if(in.length()==0){
        cout<<out<<endl;
        return;
    }
    // rec case 
    string output1=out;
    string output2=out; 
    output1.push_back(in[0]);
    
    output2.push_back(char(in[0]-32)); // space nhi lunga
    in.erase(in.begin()+0);
    solve(in,output1);
    solve(in,output2);
    return;
}
int main(){
    string in;
    cin>>in;
    string out="";
    solve(in,out);
    return 0;
}