#include<bits/stdc++.h>
using namespace std;

/*
Triangle | Fixed Starting Point and Variable Ending Point
So it's preferable to start from a fixed point rather than starting recurance from variable point
*/
// Triangle
// https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// RECURSION
// int minPathSum(vector<vector<int>> &v,int n,int i=0,int j=0){
//     if(i==n-1){
//         return v[i][j];
//     }
//     int down=minPathSum(v,n,i+1,j); // moving 
//     int diagonal=minPathSum(v,n,i+1,j+1);
//     return v[i][j]+min(down,diagonal);
// }

// TABULATION O(N^2)
// int minPathSum(vector<vector<int>> &v,int n){
//     int dp[n][n];
//     for(int i=n-1;i>=0;i--){
//         for(int j=i;j>=0;j--){
//             if(i==n-1){
//                 dp[i][j]=v[i][j];
//             }else{
//                 int down=dp[i+1][j]; // moving 
//                 int diagonal=dp[i+1][j+1];
//                 dp[i][j]=v[i][j]+min(down,diagonal);
//             }
//         }
//     }
//     return dp[0][0];
// }

// Space Optimization
int minPathSum(vector<vector<int>> &v,int n){
    vector<int> next(n,0);
    int dp[n][n];
    for(int i=n-1;i>=0;i--){
        vector<int> curr(n,0);
        for(int j=i;j>=0;j--){
            if(i==n-1){
                curr[j]=v[i][j];
            }else{
                int down=next[j]; // moving 
                int diagonal=next[j+1];
                curr[j]=v[i][j]+min(down,diagonal);
            }
        }
        next=curr;
    }
    return next[0];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<i+1;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }    
    cout<<minPathSum(v,n);
    return 0;
}