#include<bits/stdc++.h>
using namespace std;
/*Very Important
Similar to Printing of All subsets see 2.2
For printing all subsets in which the same number can be repeated
just replace i-1 with i all the steps will remain the same

Whatever the demoninations you are given and you need to find out the minimum number of coins required to get that denomination, first sort the coins in ascending order, you will be able to print the coins in ascending order therfore the first set of numbers will give you the minimum number
of coins 

*/
void print(vector<int> &v,vector<vector<bool>> &dp,int i,int j,vector<int>& temp){
    if(j<0 || dp[i][j]==0){
        return;
    }
    if(i==0 || j==0){
        for(auto x:temp){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }

    if(dp[i][j]==1){
        temp.push_back(v[i-1]);
        print(v,dp,i,j-v[i-1],temp); // include
        temp.pop_back();
        print(v,dp,i-1,j,temp); // exclude 
    }
}
void isSubsetSum(vector<int> v, int sum,int n){
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
    for(int j=1;j<=sum;j++){
        dp[0][j]=false;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(v[i-1]<=j){
                dp[i][j]=(dp[i][j-v[i-1]] || dp[i-1][j]);
            }else{
                 dp[i][j]=dp[i-1][j];
            }
        }
    }
    vector<int> temp;
    print(v,dp,n,sum,temp);
}
int main(){
    vector<int> v; // values
    int n,sum;
    cin>>n>>sum;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    isSubsetSum(v,sum,n);
    return 0;
}

// 62-73