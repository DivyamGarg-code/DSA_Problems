#include<bits/stdc++.h>
using namespace std;

// Longest Common Subsequence using Top Down Approach
// TC O(n*m) SC(n*m)
int LCS(string &x,string &y,int n,int m){
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
    // For Printing the Longest Common Subsequence
// -----------------------------------------------------------
    int len=dp[n][m];
    int cnt=0;
    int i=n;
    int j=m;
    string s;
    s.reserve(len);
    while(i!=0 && j!=0){
        if(x[i-1]==y[j-1]){
            s[len-cnt-1]=x[i-1];
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
    for(int i=0;i<len;i++){
        cout<<s[i];
    }
    cout<<endl;
// --------------------------------------------------------------
    return dp[n][m];
} 
int main(){
    string x,y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    cout<<LCS(x,y,n,m);
    return 0;
}