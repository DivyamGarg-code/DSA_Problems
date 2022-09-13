#include<bits/stdc++.h>
using namespace std;

// Permutation with spaces

void solve(string in,string out){
    // base case
    if(in.length()==0){
        cout<<out<<endl;
        return;
    }
    // rec case 
    string output1=out;
    string output2=out;
    output1.push_back('_');// space lunga 
    output1.push_back(in[0]);
    output2.push_back(in[0]); // space nhi lunga
    in.erase(in.begin()+0);
    solve(in,output1);
    solve(in,output2);
    return;
}
int main(){
    string in;
    cin>>in;
    string out="";
    out.push_back(in[0]);
    in.erase(in.begin()+0);
    solve(in,out);
    return 0;
}