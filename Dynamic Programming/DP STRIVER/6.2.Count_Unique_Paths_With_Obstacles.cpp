#include<bits/stdc++.h>
using namespace std;

/*
 eg 0 0 0
    0 -1 0
    0 0 0
*/
// int uniquePaths(vector<vector<int>> &v,int i,int j){
//     if(i==0 && j==0 && v[i][j]==0){
//         return 1;
//     }
//     if(i<0 || j<0 || v[i][j]==-1){
//         return 0;
//     }
//     int up=uniquePaths(v,i-1,j);
//     int left=uniquePaths(v,i,j-1);
//     int cnt=up+left;
//     return cnt;
// }

int uniquePaths(vector<vector<int>> &v,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 && j==0 && v[i][j]==0){
                dp[i][j]=1;
            }else if(i<0 || j<0 || v[i][j]==-1){
                dp[i][j]=0;
            }else{
                int up=0,left=0;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                dp[i][j]=up+left;
            }
        }
    }
    return dp[n][m];
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
    cout<<uniquePaths(v,n-1,m-1);
    return 0;
}