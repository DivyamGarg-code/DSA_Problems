#include<bits/stdc++.h>
using namespace std;

// TC worst case O(n*n) n strings of n size and all the strings are same
// SC O(1)
string longestCommonPrefix(vector<string> &v, int n){
    string s="";
    for(int i=0;i<v[0].length();i++){
        char ch=v[0][i];
        bool match=true;
        for(int j=1;j<n;j++){
            if(v[j].size()-1<i || ch!=v[j][i]){
                return s;
            }
        }
        s.push_back(ch);
    }
    return s;
}
int main(){
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        v.push_back(x);
    }
    cout<<longestCommonPrefix(v,n);
    
    return 0;
} 