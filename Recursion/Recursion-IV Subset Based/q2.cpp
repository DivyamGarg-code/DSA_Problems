#include<bits/stdc++.h>
using namespace std;
int str_to_int(string s){
    int ans=0;
    int k=1;
    for(int i =s.length()-1; i>=0; i--){
        int p=s[i];
        ans+=(p-'0')*k;
        k=k*10;
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    if(s[1]!='\0'){
        cout<<"Not null";
    }else{
        cout<<"Null";
    }
    return 0;
}