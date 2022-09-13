#include<bits/stdc++.h>
using namespace std;

/*
ven an array arr of size N containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   
Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)
*/

int minSubsetSum(int a[],int k,int n){
    bool dp[n+1][k+1];
    int ans=INT_MAX;
    // Find out the bool values is it posible to have asubset with sum=k
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=k;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++){ // number of elements
        for(int j=0;j<=k;j++){
            if(a[i-1]<=j){
                dp[i][j]=(dp[i-1][j-a[i-1]] || dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=(k/2);i>=0;i--){
        if(dp[n][i]==1){
            return (k-i-i);
        }
    }

}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    int range=0;
    for(int i=0;i<n;i++){
        range+=a[i];
    }
    cout<<minSubsetSum(a,range,n);
    return 0;
}