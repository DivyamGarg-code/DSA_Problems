#include<bits/stdc++.h>
using namespace std;

/*
    Palindrome Partitioning Recursive
*/
// int solve(vector<vector<int>> &t,vector<vector<int>> &dp,string &s,int i,int j){
//     if(i>=j || dp[i][j]==1){
//         return 0;
//     }
//     int min_partitions=INT_MAX;
//     for(int k=i;k<=j-1;k++){
//         int temp=1+solve(t,dp,s,i,k)+solve(t,dp,s,k+1,j);
//         if(temp<min_partitions){
//             min_partitions=temp;
//         }
//     }
//     return min_partitions;
// }

// Palindromic Partioning Memoization
// int solve(vector<vector<int>> &t,vector<vector<int>> &palindrome,string &s,int i,int j){
//     if(i>=j){
//         return 0;
//     }
//     if(palindrome[i][j]==1){
//         return 0;
//     }
//     if(t[i][j]!=-1){
//         return t[i][j];
//     }
//     int min_partitions=INT_MAX;
//     for(int k=i;k<=j-1;k++){
//         int temp=1+solve(t,palindrome,i,k)+solve(t,palindrome,k+1,j);
//         if(temp<min_partitions){
//             min_partitions=temp;
//         }
//     }
//     return t[i][j]=min_partitions;
// }

// Palindromic Partioning Memoization+Optimization
int solve(vector<vector<int>> &t,vector<vector<int>> &dp,string &s,int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]==1){
        return 0;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int min_partitions=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int left,right;
        if(t[i][k]!=-1){
            left=t[i][k];
        }else{
            left=solve(t,dp,s,i,k);
            t[i][k]=left;
        }
        if(t[k+1][j]!=-1){
            right=t[k+1][j];
        }else{
            right=solve(t,dp,s,k+1,j);
            t[k+1][j]=right;
        }
        int temp=1+left+right;
        if(temp<min_partitions){
            min_partitions=temp;
        }
    }
    return t[i][j]=min_partitions;
}
int palindromicPartition(string &s){
    int n=s.length();
    vector<vector<int>> t(n+1,vector<int>(n+1,-1));
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int cnt=n;
    int j;
    while(cnt){
        j=n-cnt;
        for(int i=0;i<cnt;i++){
            int len=j-i+1;
            if(s[i]==s[j]){
                if(len>3){
                    if(dp[i+1][j-1]==1){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=0;
                    }
                }else{
                    dp[i][j]=1;
                }
            }else{
                dp[i][j]=0;
            }
            j++;
        }
        cnt--;
    }
    return solve(t,dp,s,0,n-1);
}
int main(){
    string s;
    cin>>s;
    cout<<palindromicPartition(s);
    return 0;
}