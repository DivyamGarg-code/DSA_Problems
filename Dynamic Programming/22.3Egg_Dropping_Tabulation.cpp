#include<bits/stdc++.h>
using namespace std;

// Egg Dropping Bottom Up
// Time Complexity  : O(eggs*floors^2)
// Space Complexity : O(eggs*floors^2)
int solve(int e,int f){
    int dp[e+1][f+1];
    for(int i=1;i<=e;i++){ // eggs
        for(int j=0;j<=f;j++){ // floors
            if(j==0 || j==1){
                dp[i][j]=j;
            }else if(i==1){
                dp[i][j]=j;
            }else{
                int min_attempts=INT_MAX;
                for(int k=1;k<=j;k++){
                    int temp=1+max(dp[i-1][k-1],dp[i][j-k]);
                    min_attempts=min(temp,min_attempts);
                }
                dp[i][j]=min_attempts;
            }
        }
    }
    return dp[e][f];
}
int main(){
    int eggs,floors;
    cin>>eggs>>floors;
    cout<<solve(eggs,floors);
    return 0;
}