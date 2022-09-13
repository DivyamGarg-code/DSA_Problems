#include<bits/stdc++.h>
using namespace std;

// // Recursive code for minimum number of coins TC O(2^n) SC O(n)
// int countCoins(int a[],int sum,int i){
//     if(sum==0){
//         return 0;
//     }
//     if(i<0 || sum<0){
//         return INT_MAX-1;
//     }
//     return min((countCoins(a,sum-a[i],i)+1),countCoins(a,sum,i-1));
// }

// Time Complexity O(n*sum) Space Complexity O(n*sum)
int minCoins(int coins[], int n, int sum) { 
    if(n==0){
        return -1;
    }
    int dp[n+1][sum+1];
    // for(int i=0;i<=n;i++){
    //     dp[i][0]=0;
    // }
    // for(int j=1;j<=sum;j++){
    //     dp[0][j]=INT_MAX-1;
    //     if(j%coins[0]==0){
    //         dp[1][j]=j/coins[0];
    //     }else{
    //         dp[1][j]=INT_MAX-1;
    //     }
    // }
    // for(int i=2;i<=n;i++){
    //     for(int j=0;j<=sum;j++){
    //         if(coins[i-1]<=j){
    //             dp[i][j]=min((1+dp[i][j-coins[i-1]]),dp[i-1][j]);
    //         }else{
    //             dp[i][j]=dp[i-1][j];
    //         }
    //     }
    // }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0){
                dp[i][j]=0;
            }else if(i==0){
                dp[i][j]=INT_MAX-1;
            }else if(coins[i-1]<=j){
                dp[i][j]=min((1+dp[i][j-coins[i-1]]),dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    if(dp[n][sum]==INT_MAX-1){
        return -1;
    }
    return dp[n][sum];
} 

int main(){
    int n,sum;
    cin>>n>>sum;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<minCoins(a,n,sum);
    return 0;
}
