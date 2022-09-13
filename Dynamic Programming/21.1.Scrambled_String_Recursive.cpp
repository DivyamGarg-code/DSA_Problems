#include<bits/stdc++.h>
using namespace std;

// Scrambled String
bool solve(string a,string b){
    if(a.compare(b)==0){
        return true;
    }
    if(a.length()<=1){
        return false;
    }
    int n=a.length();
    for(int i=1;i<=n-1;i++){
        if((solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i))) || (solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)))){
            // ie it is a scrambled string
            return true;
        }
    }
    return false;
}
int main(){
    string a,b;
    cin>>a>>b;
    if(a.length()!=b.length()){
        cout<<0;
    }else{

        cout<<solve(a,b);
    }
    return 0;
}