#include<bits/stdc++.h>
using namespace std;

/*
    VERY IMPORTANT TOPIC
    DP ON GRIDS

    Q1. NUMBER OF WAYS TO REACH FROM SOURCE (0,0) TO DESTINATION (N-1,M-1)
*/

// Recursion TC O(2^N*M)
// int uniquepaths(int i,int j){
//     if(i==0 && j==0){
//         return 1;
//     }
//     if(i<0){
//         return 0;
//     }
//     if(j<0){
//         return 0;
//     }
//     int up=uniquepaths(i-1,j);
//     int left=uniquepaths(i,j-1);
//     int cnt=up+left;
//     return cnt;

// }

// TABULATION TC O(N*M)
/*
For Space Optimization replace dp[i-1] with prev/dp[i+1] with next and dp[i] with curr blindly and after that do prev/next=curr;
*/
// int uniquePaths(int n,int m){
//     int dp[n+1][m+1];
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=m;j++){
//             if(i==0 && j==0){
//                 dp[i][j]=1;
//             }else{
//                 int up=0,left=0;
//                 if(i>0){
//                     up=dp[i-1][j];
//                 }
//                 if(j>0){
//                     left=dp[i][j-1];
//                 }
//                 dp[i][j]=up+left;
//             }
//         }
//     }
//     return dp[n][m];
// }

// If there is a previous row and previous column then we can do the space optimization
// Space complexity O(m)
int uniquePaths(int n,int m){
    vector<int> prev(m+1,0);
    for(int i=0;i<=n;i++){
        vector<int> curr(m+1,0);
        for(int j=0;j<=m;j++){
            if(i==0 && j==0){
                curr[i]=1;
            }else{      
                int up=0,left=0;
                if(i>0){
                    up=prev[j];
                }
                if(j>0){
                    left=curr[j-1];
                }
                curr[j]=up+left;
            }
        }
        prev=curr; // swap the vectors
    }
    return prev[m];
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<uniquePaths(n-1,m-1);
    return 0;
}