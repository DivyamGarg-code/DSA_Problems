#include<bits/stdc++.h>
using namespace std;

// Longest Common Substring Length Recursive Code
// int LCS(string &x, string &y, int n, int m,int cnt=0){
//     if(n==0 || m==0){
//         return cnt;
//     }
//     if(x[n-1]==y[m-1]){
//         cnt=LCS(x,y,n-1,m-1,cnt+1);
//     }
//     cnt=max(cnt,(max(LCS(x,y,n-1,m,0),LCS(x,y,n,m-1,0))));
//     return cnt;
// }

// Time Complexity: O(m*n) 
// Auxiliary Space: O(m*n)

// Longest Common Substring Length Top Down Code Along with the printing of all the substrings along with maximum substring
int LCS(string x, string y, int n, int m){
    int dp[n+1][m+1];
    int cnt=INT_MIN;
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];                
// ------------------------------------------------------
                // Printing all substrings
                int a=i-dp[i][j]+1;
                int temp=1;
                while(temp<=dp[i][j]){
                    cout<<x[a-1];
                    a++;
                    temp++;
                }
                cout<<endl; 
// --------------------------------------------------------
            }else{
                dp[i][j]=0;
            }
            cnt=max(cnt,dp[i][j]);
            // Here if you want to print only the substring with maximum length then store the maximum count along with it's ith and jth index, then simple follow the above step of printing that string
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
   
    return cnt;
}
int main(){
    string x,y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    cout<<LCS(x,y,n,m);
    return 0;
}