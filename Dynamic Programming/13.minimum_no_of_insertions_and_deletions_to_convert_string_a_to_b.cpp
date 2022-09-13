#include<bits/stdc++.h>
using namespace std;

// Minimum Number of Insertion and Deletion to convert String a to String b

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
    int len=dp[n][m];
    int insertions=m-dp[n][m];
    int deletions=n-dp[n][m];
    return insertions+deletions;
    
}
int main(){
    string x,y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    cout<<LCS(x,y,n,m);
    return 0;
}