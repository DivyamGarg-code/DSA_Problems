#include<bits/stdc++.h>
using namespace std;

/* Shortest Common SuperSequence
Shortest Common SuperSequence
Given two strings str1 and str2, find the shortest string such that after merging s1 and s2 we get a shortest string which contains both s1 and s2
Examples:
Input:   str1 = "geek",  str2 = "eke" 
Adfter concatination we'll get geekeke -> super sequence
Output: "geeke"

Input: aggtab gxtxayb  LCS of both string is gtab so delete it from any 1 string we will get length of shortest common supersequence
aggxtxayb
Formula:  (n+m)-LCS(s1,s2)

Recursive Approach
int lcs(string &x,string &y,int n,int m,int cnt=0){
    if(n==0 || m==0){
        return cnt;
    }
    if(x[n-1]==y[m-1]){
        cnt=lcs(x,y,n-1,m-1,cnt+1);
    }
    cnt=max(cnt,max(lcs(x,y,n-1,m,0),lcs(x,y,n,m-1,0)));
    return cnt;
}

*/

void shortestCommonSupersequence(string &x,string &y,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    int len=dp[n][m];
    cout<<"Length of shortest common supersequence is"<<((m+n)-dp[n][m])<<endl;
// ---------------------------------------------------    
// Printing the shortest common supersequence
    int i=n;
    int j=m;
    string s;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }else{
            if(dp[i][j-1]>dp[i-1][j]){
                s.push_back(y[j-1]);
                j--;
            }else{
                s.push_back(x[i-1]);
                i--;
            }
        }
    }
    while(i>0){
        s.push_back(x[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(y[j-1]);
        j--;
    }

    for(int i=0;i<s.length()/2;i++){
        swap(s[i],s[s.length()-i-1]);
    }
    for(auto x:s){
        cout<<x;
    }
// ------------------------------------------------------ /
}
int main(){
    string x,y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    shortestCommonSupersequence(x,y,n,m);
    return 0;
}