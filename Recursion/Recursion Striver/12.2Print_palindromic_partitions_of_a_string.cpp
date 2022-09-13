#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s){
    int n=s.length();
    if(n==1){
        return true;
    }
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]){
            return false;
        }
    }
    return true;
}
void print(string &a,int n,vector<string> temp,string s,int i=0){
    if(i==n){
        if(temp.size()==1){
            if(isPalindrome(temp[0])){
                for(auto x:temp){
                    cout<<x<<" ";
                }
                cout<<endl;
            }
        }else{
            if(isPalindrome(temp[temp.size()-1])){
                for(auto x:temp){
                    cout<<x<<" ";
                }
                cout<<endl;
            }
        }
        return;
    }
    // here let's assume case of non partitioning ie concatinate
    // s.push_back('0');
    s.push_back(a[i+1]);
    if(temp.empty()){
        temp.push_back(s);
    }else{
        temp[temp.size()-1]=s;
    }
    print(a,n,temp,s,i+1);
    s.pop_back();
    temp[temp.size()-1].pop_back();

    // here let's assume case of partitioning ie dont concatinate
    if(isPalindrome(s)){
        if(temp.empty()){
            temp.push_back(s);
        }
        s="";
        s.push_back(a[i+1]);
        temp.push_back(s);
        print(a,n,temp,s,i+1);
    }else{
        return;
    }
}
int main(){
    string a;
    cin>>a;
    int n=a.length()-1;
    vector<string> temp;
    string s;
    s.push_back(a[0]);
    print(a,n,temp,s);
    return 0;
}