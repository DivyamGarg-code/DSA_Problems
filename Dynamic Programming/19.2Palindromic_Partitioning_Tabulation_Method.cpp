#include<bits/stdc++.h>
using namespace std;

/*
    Palindrome Partitioning Recursive
*/
// int solve(vector<vector<int>> &t,vector<vector<int>> &palindrome,string &s,int i,int j){
//     if(i>=j || palindrome[i][j]==1){
//         return 0;
//     }
//     if(t[i][j]!=-1){
//         return t[i][j];
//     }
//     int min_partitions=INT_MAX;
//     for(int k=i;k<=j-1;k++){
//         int temp=1+solve(t,palindrome,s,i,k)+solve(t,palindrome,s,k+1,j);
//         if(temp<min_partitions){
//             min_partitions=temp;
//         }
//     }
//     return t[i][j]=min_partitions;
// }

/* Palindromic Partioning Most Optimized
 Time Complexity O(n^2) 
 Space Complexity O(n^2) 
*/
int palindromicPartition(string &s){
    int n=s.length();
    vector<vector<int>> palindrome(n,vector<int>(n,-1));
    int cnt=n;
    int j;
    while(cnt){ // Store the bool value is the substring palindrome or not
        j=n-cnt;
        for(int i=0;i<cnt;i++){
            int len=j-i+1;
            if(s[i]==s[j]){
                if(len>3){
                    if(palindrome[i+1][j-1]==1){
                        palindrome[i][j]=1;
                    }else{
                        palindrome[i][j]=0;
                    }
                }else{
                    palindrome[i][j]=1;
                }
            }else{
                palindrome[i][j]=0;
            }
            j++;
        }
        cnt--;
    }
    int dp[n][n];
    cnt=n;
    while(cnt){ // storing the partitions in the 2d matrix diagonally
        j=n-cnt;
        for(int i=0;i<cnt;i++){
            if(i>=j || palindrome[i][j]==1){
                dp[i][j]=0;
            }else{
                int temp;
                int min_partitions=INT_MAX;
                for(int k=i;k<=j-1;k++){
                    temp=1+dp[i][k]+dp[k+1][j];
                    if(temp<min_partitions){
                        min_partitions=temp;
                    }
                }
                dp[i][j]=min_partitions;
            }
            j++;
        }
        cnt--;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(i>j){
    //             cout<<0<<" ";
    //             continue;
    //         }
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }     
    return dp[0][n-1];

}
int main(){
    string s;
    cin>>s;
    cout<<palindromicPartition(s);
    return 0;
}