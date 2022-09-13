#include<bits/stdc++.h>
using namespace std;

/*
Longest Repeating Subsequence
The only difference is i!=j
for eg I/P string: AAABEBCDD
O/P ABD
*/
int lcs(string &s,int n){
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else if(s[i-1]==s[j-1] && i!=j){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][n]<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int i=n;
    int j=n;
    string ans;
    while(i!=0 && j!=0){
        if(s[i-1]==s[j-1] && i!=j){
            ans.push_back(s[i-1]);
            i--;
            j--;
        }else{
            if(dp[i][j-1]>=dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    for(int i=0;i<ans.length()/2;i++){
        swap(ans[i],ans[ans.length()-i-1]);
    }
    for(auto x:ans){
        cout<<x;
    }
    cout<<endl;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    lcs(s,n);
    return 0;
}