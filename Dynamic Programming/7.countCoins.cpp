#include<bits/stdc++.h>
using namespace std;

// return the count of all the possible combinations whose sum is equal to the given sum

int change(int sum, vector<int>& coins) {
    int n=coins.size();
    if(n==0){
        return -1;
    }
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0){
                dp[i][j]=1;
            }else if(i==0){
                dp[i][j]=0;
            }else if(coins[i-1]<=j){
                dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int> coins;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        coins.push_back(x);
    }
    cout<<change(sum,coins);
    return 0;
}