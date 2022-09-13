#include<bits/stdc++.h>
using namespace std;
// Sequence Pattern Matching Time Complexity O(m*n)
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
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    if(dp[n][m]==min(n,m)){
        return 1;
    }
    return 0;
}
int main(){
    string x,y;
    cin>>x,y;
    int n=x.length();
    int m=y.length();
    LCS(x,y,n,m);
    return 0;
}