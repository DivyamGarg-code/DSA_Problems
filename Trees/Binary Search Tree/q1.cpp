#include<bits/stdc++.h>
using namespace std;

int solve(int i,int n){
    if(i<=0){
        return 0;
    }
    int l=solve(i-1,i-1); // left se sare possible bst's lekr aayga
    int r=solve(n-i,n-i); // right se sare possible bst's lekr aayga
    if(l==0 && r==0){
        return 1;
    }else if(l!=0 && r!=0){
        return l+r+5;
    }else if(l!=0 && r==0){
        return l+2;
    }else if(l==0 && r!=0){
        return r+2;
    }
}

int ans(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=solve(i,n);
    }
}


int main(){
    int n;
    cin>>n;
    solve(1,n);
    return 0;
}