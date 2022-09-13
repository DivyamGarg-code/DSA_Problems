#include<bits/stdc++.h>
using namespace std;

/* Letter Case Permutation 
    input - a1B1
    output - a1B1 a1b1 A1B1 A1b1
    And storing the output in the vector
*/

void solve(string in,string out,vector<string> &v){
    // base case
    if(in.length()==0){
        //cout<<out<<endl;
        v.push_back(out);
        return;
    }
    // rec case 
    string output1=out;
    string output2=out;
    if(int(in[0])>=int('0') && int(in[0])<=int('9')){
        out.push_back(in[0]);
        in.erase(in.begin()+0);
        solve(in,out);
    }else{ 
        output1.push_back(in[0]); // no change 
        if(int(in[0])>=int('a') && int(in[0])<=int('z')){
            output2.push_back(char(in[0]-32)); // change into capital letters
        }else if(int(in[0])>=int('A') && int(in[0])<=int('Z')){
            output2.push_back(char(in[0]+32)); // change into small letters
        }else{
            output2.push_back(in[0]);
        }
        in.erase(in.begin()+0);
        solve(in,output1);
        solve(in,output2);
    }
    return;
}
int main(){
    string in;
    cin>>in;
    string out="";
    vector<string> v;
    solve(in,out,v);
    return 0;
}