#include<bits/stdc++.h>
using namespace std;

/* Longest Palindromic Subsequence
    basically you are given a string s , find the reverse of this  string  and the lcs of both will give the longest palindromic subsequence

    LPS=LCS(s,reverse(s))

    input:    agbcba
    reverse:  abcbga
    LCS:      abcba

*/
int LCS(string &x,int n){
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else if(x[i-1]==x[n-j]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    // Printing the LPS
//-------------------------------------------------------
    int cnt=0;
    int i=n;
    int j=n;
    string s;
    s.reserve(dp[n][n]);
    while(i!=0 && j!=0){
        if(x[i-1]==x[n-j]){
            s[dp[n][n]-cnt-1]=x[i-1];
            cnt+=1;
            i--;
            j--;
        }else{
            if(dp[i][j-1]>=dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    for(int i=0;i<dp[n][n];i++){
        cout<<s[i];
    }
    cout<<endl;
//-------------------------------------------------------    
    return dp[n][n];
    
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    cout<<LCS(s,n);
    return 0;
}