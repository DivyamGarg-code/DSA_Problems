#include<bits/stdc++.h>
using namespace std;

int count(int n,int dp[]){
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
    return dp[n]=(count(n-1,dp)%1000000007+count(n-2,dp)%1000000007+count(n-3,dp)%1000000007)%1000000007;
}
int countDistinctWays(int n) {
    if(n==0){
        return 1;
    }
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    return count(n,dp);
}

int main(){
    int n;
    cin>>n;
    cout<<countDistinctWays(n);
    return 0;
}

/*
51
1
76
18
54
9
49
26
49
22

951279875
1
662189184
4181
583861472
55
586268941
196418
586268941
28657

-1408458269
1
-1036647147
4181
2144908973
55
-298632863
196418
-298632863
28657

*/