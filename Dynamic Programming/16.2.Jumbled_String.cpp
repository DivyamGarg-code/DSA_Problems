#include<bits/stdc++.h>
using namespace std;
/*
You are provided an input string S and the string “GEEKS” . Find the number of ways in which the subsequence “GEEKS” can be formed from the string S.
*/
// int solve(string &x,string &y,int n,int m){
//     if(m==0){
//         return 1;
//     }
//     if(n<=0 || n<m){ // not equal to zero
//         return 0;
//     }
//     int cnt=0;
//     if(x[n-1]==y[m-1]){
//         cnt=solve(x,y,n-1,m)+solve(x,y,n-1,m-1);
//     }else{
//         cnt=solve(x,y,n-1,m);
//     }
//     return cnt;
// }

// Time Complexity : O(N * M)
// Space Complexity : O(N * M)
int solve(string &x,string &y,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j==0){
                dp[i][j]=1;
            }else if(i<=0 || i<j){
                dp[i][j]=0;
            }else{
                if(x[i-1]==y[j-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][m];
    
}
int main(){
    string x,y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    cout<<solve(x,y,n,m);
    return 0;
}