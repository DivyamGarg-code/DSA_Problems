#include<bits/stdc++.h>
using namespace std;

// VARIABLE STARTING AND ENDING POINTS 
// Minimum/Maximum Falling Path Sum
/*
RECURSION
int f(vector<vector<int>> &v,int m,int i,int j){
    if(i==0 && j>=0 && j<m){
        return v[i][j];
    }
    if(i<0 || j<0 || j>=m){
        return INT_MIN;
    }
    int tl=f(v,m,i-1,j-1);
    int tr=f(v,m,i-1,j+1);
    int t=f(v,m,i-1,j);
    return v[i][j]+max(max(tl,tr),t);
}
int maxSum(vector<vector<int>> &v,int n,int m){
    int ans=INT_MIN;
    for(int k=0;k<m;k++){
        ans=max(ans,f(v,m,n-1,k));
    }
    return ans;
}
*/

int f(vector<vector<int>> &v,int n,int m){
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                dp[i][j]=v[i][j];
            }else{
                int tl=INT_MIN;
                int tr=INT_MIN;
                int t=INT_MIN;
                if(i>0 && (j-1)>=0 && (j-1)<m){
                    tl=dp[i-1][j-1];
                }
                if(i>0 && (j+1)>=0 && (j+1)<m){
                    tr=dp[i-1][j+1];
                }
                if(i>0 && j>=0 && j<m){
                    t=dp[i-1][j];
                }
                dp[i][j]=v[i][j]+max(max(tl,tr),t);
            }
        }
    }
    int ans=INT_MIN;
    for(int k=0;k<m;k++){
        ans=max(ans,dp[n-1][k]);
    }
    return ans;
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
    cout<<f(v,n,m);
    // cout<<maxSum(v,n,m);
    return 0;
}