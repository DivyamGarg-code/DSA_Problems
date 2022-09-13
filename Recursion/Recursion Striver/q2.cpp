#include<bits/stdc++.h>
using namespace std;
int cnt=1;
void print(string &s,int n,int i=0){
    if(i==n){
        for(auto x:s){
            cout<<x<<" ";
        }
        cout<<" cnt ->"<<cnt;
        cnt++;
        cout<<endl;
    }
    for(int j=i;j<n;j++){
        swap(s[i],s[j]);
        print(s,n,i+1);
        swap(s[i],s[j]);
    }
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    print(s,n);
    return 0;
}