#include<bits/stdc++.h>
using namespace std;

// Time Complexity O(2^n)
// int steps(int n){ // Recursive Approach
//     if(n<=0){
//         return 0;
//     }
//     if(n==1){
//         return 1;
//     } 
//     if(n==2){
//         return 2;
//     }
//     int cnt=steps(n-1)+steps(n-2);
//     return cnt;
// }

/*
int count(int n,int dp[]){ // memoization
    if(dp[n]!=-1){
        return dp[n];
    }
    if(n<=0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return dp[n]=count(n-1,dp)+count(n-2,dp);
}
int countDistinctWays(int n) {
    if(n==0){
        return 1;
    }
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    return count(n,dp);
}
*/

// Time complexity O(n)
// space Complexity O(n)
// int steps(int n){ // Bottom Up Approach
//     int dp[n+1];
//     for(int i=0;i<=n;i++){
//         if(i<=0){
//             dp[i]=0;
//         }else if(i==1){
//             dp[i]=1;
//         }else if(i==2){
//             dp[i]=2;
//         }else{
//             dp[i]=dp[i-1]+dp[i-2];
//         }
//     }
//     return dp[n];
// }

// Time Complexity O(n)
// Optimized Space Complexity O(1)
int steps(int n){ // Bottom Up Approach
    int dp[n+1];
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    int a=1,b=2;
    int c;
    for(int i=3;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main(){
    int n;
    cin>>n;
    cout<<steps(n);
    return 0;
}