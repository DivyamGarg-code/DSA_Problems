#include<bits/stdc++.h>
#define mod 1003
using namespace std;

int dp[205][205][2];

int solve(string s, int i, int j, bool isTrue){
    if(i>j) return 0;
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    if(i==j){
        if(isTrue)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    int ans=0;
    for(int k=i+1; k<j; k+=2){
        if(dp[i][k-1][1]==-1)
            dp[i][k-1][1] = solve(s, i, k-1, true);
        if(dp[i][k-1][0]==-1)
            dp[i][k-1][0] = solve(s, i, k-1, false);
        if(dp[k+1][j][1]==-1)
            dp[k+1][j][1] = solve(s, k+1, j, true);
        if(dp[k+1][j][0]==-1)
            dp[k+1][j][0] = solve(s, k+1, j, false);
        if(s[k]=='&'){
            if(isTrue)
                ans += (dp[k+1][j][1]*dp[i][k-1][1])%mod;
            else
                ans += ((dp[k+1][j][1]*dp[i][k-1][0])%mod + (dp[k+1][j][0]*dp[i][k-1][1])%mod + (dp[k+1][j][0]*dp[i][k-1][0])%mod)%mod;
        }
        else if(s[k]=='|'){
            if(isTrue)
                ans += ((dp[k+1][j][1]*dp[i][k-1][0])%mod + (dp[k+1][j][0]*dp[i][k-1][1])%mod + (dp[k+1][j][1]*dp[i][k-1][1])%mod)%mod;
            else
                ans += (dp[k+1][j][0]*dp[i][k-1][0])%mod;
        }
        else{
            if(isTrue)
                ans += ((dp[k+1][j][1]*dp[i][k-1][0])%mod + (dp[k+1][j][0]*dp[i][k-1][1])%mod)%mod;
            else
                ans += ((dp[k+1][j][1]*dp[i][k-1][1])%mod + (dp[k+1][j][0]*dp[i][k-1][0])%mod)%mod;
        }
    }
    return ans%mod;
}


int main()
 {
	int t;
	cin >> t;
	int n;
	while(t-- && cin >> n){
	    memset(dp, -1, sizeof(dp));
	    string s;
	    cin >> s;
	    cout << solve(s, 0, n-1, true) << endl;
	}
	return 0;
}