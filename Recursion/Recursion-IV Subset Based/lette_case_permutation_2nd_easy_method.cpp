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
        v.push_back(out);
        return;
    }
    // rec case 
    if(isalpha(in[0])){ // will check is my character is the alphabet or not
        string output1=out;
        string output2=out;
        output1.push_back(tolower(in[0]));
        output2.push_back(toupper(in[0]));
        in.erase(in.begin()+0);
        solve(in,output1,v);
        solve(in,output2,v);
    }else{ // ie my char is  not an alphabet
        string output1=out;
        output1.push_back(in[0]);
        in.erase(in.begin()+0);
        solve(in,output1,v);

    }
    return;
}
int main(){
    string in;
    cin>>in;
    string out="";
    vector<string> v;
    solve(in,out,v);
    for(auto x:v){
        cout<<x<<endl;
    }
    return 0;
}