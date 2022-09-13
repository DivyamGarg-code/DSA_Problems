#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool> mp;
// Scrambled String Using Map
//Time Complexity: O(N^2), where N is the length of the given strings.
// Auxiliary Space: O(N^2), As we need to store O(N^2) string in our mp map.
bool solve(string a,string b){
    if(a.compare(b)==0){
        return true;
    }
    if(a.length()<=1){
        return false;
    }
    int n=a.length();
    bool flag=false;
    string temp=a+' '+b;
    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }
    for(int i=1;i<n;i++){
        if((solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i))) || (solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)))){
            flag=true;
            break;
        }
    }
    return mp[temp]=flag;
}
int main(){
    string a,b;
    cin>>a>>b;
    if(a.length()!=b.length()){
        cout<<0;
    }else if(a.empty() && b.empty()){
        cout<<1;
    }else{
        cout<<solve(a,b);
    }
    return 0;
}