#include<bits/stdc++.h>
using namespace std;
// Boolean Parenthesization
// RECURSIVE APPROACH
int solve(string &s,int i,int j,bool isTrue){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue==true){
            return s[i]=='T';
        }else{
            return s[i]=='F';
        }
    }
    int ans=0;
    for(int k=i+1;k<j;k+=2){
        int lt=solve(s,i,k-1,true);
        int lf=solve(s,i,k-1,false);
        int rt=solve(s,k+1,j,true);
        int rf=solve(s,k+1,j,false);
        if(s[k]=='&'){
            if(isTrue==true){
                ans+=lt*rt;
            }else{
                ans+=lt*rf+lf*rt+lf*rf;
            }
        }else if(s[k]=='|'){
            if(isTrue==true){
                ans+=lt*rf+lf*rt+lt*rt;
            }else{
                ans+=lf*rf;
            }
        }else if(s[k]=='^'){
            if(isTrue==true){
                ans+=lt*rf+lf*rt;
            }else{
                ans+=lt*rt+lf*rf;
            }
        }
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    cout<<solve(s,0,n-1,true);
    return 0;
}