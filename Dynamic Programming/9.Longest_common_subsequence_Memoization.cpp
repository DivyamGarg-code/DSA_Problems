#include<bits/stdc++.h>
using namespace std;
// LONGEST COMMON SUBSEQUENCE
// Recusive Solution
// int solve(vector<vector<int>> &t,string &x,string &y,int n,int m){
//     if(n==0 || m==0){
//         return 0;
//     }
//     if(x[n-1]==y[m-1]){
//         return 1+solve(t,x,y,n-1,m-1);
//     }else{
//         return max(solve(t,x,y,n,m-1),solve(t,x,y,n-1,m));
//     }
// } 

// Longest Common Subsequence using Memoization
// slower than the top down approach
int solve(vector<vector<int>> &t,string &x,string &y,int n,int m){
    if(n==0 || m==0){
        return t[n][m]=0;
    }
    if(t[n][m]!=-1){
        return t[n][m];
    }
    if(x[n-1]==y[m-1]){
        return t[n][m]=1+solve(t,x,y,n-1,m-1);
    }else{
        return t[n][m]=max(solve(t,x,y,n,m-1),solve(t,x,y,n-1,m));
    }
} 
int LCS(string &x,string &y,int n,int m){
    vector<vector<int>> t(n+1,vector<int>(m+1,-1));
    return solve(t,x,y,n,m);
}
int main(){
    string x,y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    // string ans="";
    cout<<LCS(x,y,n,m);
    return 0;
}