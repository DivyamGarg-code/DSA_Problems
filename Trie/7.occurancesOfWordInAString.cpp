#include<bits/stdc++.h>
using namespace std;

// number of occurances of word in a string
// TC roughly O(n*k) and exact O(n+(number of occurances of word in the string)*word.length)
// SC O(1)
bool isPresent(string &s,string &p,int idx){
    int j=0;
    int i=idx;
    int sl=s.length();
    int pl=p.length();
    if(sl-idx<pl){
        return false;
    }
    for(int i=idx;i<s.length();i++){
        if(s[i]==p[j]){
            j++;
            if(j==pl){
                return true;
            }
        }else{
            return false;
        }
    }
}
int main(){
    string s;
    string p;
    cin>>s>>p;
    char ch=p[0];
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==ch){
            if(isPresent(s,p,i)){
                cout<<"Present at index : "<<i<<endl;
                ans+=1;
            }
        }   
    }
    cout<<ans;
    return 0;
}