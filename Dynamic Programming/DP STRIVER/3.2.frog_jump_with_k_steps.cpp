#include<bits/stdc++.h>
using namespace std;

//  Frog Jump with K Distance ie i+1,i+2,i+k jumps
// Recursive solution
// int f(int i,int k,int h[]){
//     if(i==0){
//         return 0;
//     }
//     int min_energy=INT_MAX;
//     for(int j=1;j<=k;j++){
//         if((i-j)<0){
//             continue;
//         }else{
//             min_energy=min(min_energy,f(i-j,k,h)+abs(h[i]-h[i-j]));
//         }

//     }
//     return min_energy;

// }

// Memoization Time complexity O(n*k)
int f(int i,int k,int h[],int dp[]){
    if(i==0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int min_energy=INT_MAX;
    for(int j=1;j<=k;j++){
        if((i-j)<0){
            continue;
        }else{
            min_energy=min(min_energy,f(i-j,k,h,dp)+abs(h[i]-h[i-j]));
        }

    }
    return dp[i]=min_energy;
}
/*
Tabulation
int f(int n,int k,int h[]){
    int dp[n+1];
    for(int i=0;i<=n;i++){
        if(i==0){
            dp[i]=0;
        }else{
            int min_energy=INT_MAX;
            for(int j=1;j<=k;j++){
                if((i-j)<0){
                    continue;
                }else{
                    min_energy=min(min_energy,dp[i-j]+abs(h[i]-h[i-j]));
                }

            }
            dp[i]=min_energy;
        }
    }

}
*/
int main(){
    int n,k;
    cin>>n>>k;
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int dp[n];
    memset(dp,-1,sizeof(dp));
    cout<<f(n-1,k,h,dp);
    return 0;
}