#include<bits/stdc++.h>
using namespace std;

// Minimum Path Sum in Grid

// RECURSION
// int minSum(vector<vector<int>> &v,int i,int j){
//     if(i==0 && j==0){
//         return v[i][j];
//     }
//     if(i<0 || j<0){ // goes out of boundary
//         return INT_MAX;
//     }
//     int left=minSum(v,i,j-1);
//     int up=minSum(v,i-1,j);
//     return v[i][j]+min(left,up);
// }

// TABULATION / BOTTOM UP
// int minSum(vector<vector<int>> &v,int n,int m){
//     int dp[n+1][m+1];
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=m;j++){
//             if(i==0 && j==0){
//                 dp[i][j]=v[i][j];
//             }else{
//                 int left=INT_MAX,up=INT_MAX;
//                 if(i>0){
//                     up=dp[i-1][j];
//                 }
//                 if(j>0){
//                     left=dp[i][j-1];
//                 }
//                 dp[i][j]=v[i][j]+min(left,up);
//             }
//         }
//     }
//     return dp[n][m];
// }

// SPACDE OPTIMIZATION
int minSum(vector<vector<int>> &v,int n,int m){
    vector<int> prev(m+1,0);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            vector<int> curr(m+1,0);
            if(i==0 && j==0){
                curr[j]=v[i][j];
            }else{
                int left=INT_MAX,up=INT_MAX;
                if(i>0){
                    up=prev[j];
                }
                if(j>0){
                    left=curr[j-1];
                }
                curr[j]=v[i][j]+min(left,up);
            }
            prev=curr;
        }
    }
    return prev[m];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    cout<<minSum(v,n-1,m-1);
    return 0;
}