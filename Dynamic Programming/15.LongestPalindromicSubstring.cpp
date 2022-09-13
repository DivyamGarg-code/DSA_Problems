#include<bits/stdc++.h>
using namespace std;
/*
Brute Force Will Take O(n^2*n) ie n^3 time as we will be checking for every substring that ids it a palindrome or not
--------------------------------------------
Dynamic Programming Approach
Longest Palindromic substring
Time complexity O(n^2)
step1. s[start]=s[end]
step2. If len>3 dp[start+1][end-1] is it palindrome or not
*/
void LPSS(string &x,int n){
    int dp[n][n]; // rows are indicating the starting index and columns are indicating the ending index
    int maxi=INT_MIN;
    int s,e,j;
    int cnt=n;
    while(cnt){
        j=n-cnt;
        for(int i=0;i<cnt;i++){
            int len=j-i+1;
            if(x[i]==x[j]){
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
            if(dp[i][j]==1 && maxi<len){
                s=i;
                e=j;
                maxi=len;
            }
            j++;
        }
        cnt--;
    }
    string ans;
    for(int i=s;i<=e;i++){
        ans.push_back(x[i]);
    }
    for(auto x:ans){
        cout<<x;
    }
    return;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    LPSS(s,n);
    return 0;
}

// int n;
    // cin>>n;
    // char ch[n][n];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cin>>ch[i][j];
    //     }
    // }
    // int j;
    // int cnt=n;
    // while(cnt){
    //     j=n-cnt;
    //     for(int i=0;i<cnt;i++){
    //         cout<<ch[i][j]<<" ";
    //         j++;
    //     }
    //     cout<<endl;
    //     cnt--;
    // }