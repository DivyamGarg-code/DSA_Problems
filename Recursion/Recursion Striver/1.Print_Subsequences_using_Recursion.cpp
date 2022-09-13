#include<bits/stdc++.h>
using namespace std;
// Time complexity O(2^n*n) SC O(n)
void printSubsequences(string s,int n,int i=0,string ans=""){
    if(i>=n){
        cout<<ans<<endl;
        return;
    }
    ans.push_back(s[i]);
    printSubsequences(s,n,i+1,ans); // take
    ans.pop_back();
    printSubsequences(s,n,i+1,ans); // not take
}
int main(){
    string s;
    getline(cin,s);
    int n;
    n=s.length();
    printSubsequences(s,n);
    return 0;
}