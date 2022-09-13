#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> v, int sum,int n){
    bool dp[n+1][sum+1];
    for(int j=1;j<=sum;j++){
        dp[0][j]=false;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(v[i-1]<=j){
                dp[i][j]=(dp[i-1][j-v[i-1]] || dp[i-1][j]);
            }else{
                 dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];

}
int main(){
    vector<int> v; // weights
    int n,sum;
    cin>>n>>sum;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<isSubsetSum(v,sum,n);
    return 0;
}