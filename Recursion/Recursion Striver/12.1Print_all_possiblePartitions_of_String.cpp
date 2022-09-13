#include<bits/stdc++.h>
using namespace std;

void print(string &a,int n,vector<string> temp,string s,int i=0){
    if(i==n){
        for(auto x:temp){
            cout<<x<<" ";
        }
        cout<<endl;
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
    // s.push_back('1');
    if(temp.empty()){
        temp.push_back(s);
    }
    s="";
    s.push_back(a[i+1]);
    temp.push_back(s);
    print(a,n,temp,s,i+1);
    // s.pop_back();
    // temp.pop_back();
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