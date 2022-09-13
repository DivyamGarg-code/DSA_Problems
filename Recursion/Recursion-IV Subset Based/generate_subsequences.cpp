#include<bits/stdc++.h>
using namespace std;
void solve(string in,string out,vector<string> &s){
    //base case 
    if(in.length()==0){
        //cout<<out<<endl;
        s.push_back(out);
        return;
    }
    // rec case
    // copy the output in further 2 cases
    string output1=out; // in this nhi lenge 
    string output2=out; // in this le lenge
    output2.push_back(in[0]);
    in.erase(in.begin()+0);
    solve(in,output1,s);
    solve(in,output2,s);
    return;

}
bool compare(string a,string b){ // If you want to print in the lexiographical order
    return a<b;
}
int main(){
    string in;
    cin>>in;
    string out=" ";
    vector<string> s;
    solve(in,out,s);
    sort(s.begin(),s.end(),compare);
    for(auto i:s){
        cout<<i<<endl;
    }
    return 0;
}