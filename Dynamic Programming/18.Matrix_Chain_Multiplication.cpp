#include<bits/stdc++.h>
using namespace std;

/*
    MATRIX CHAIN MULTIPLICATION 
    TIME COMPLEXITY O(N*N)
    BOTTOM UP DP OR MEMOIZATION
*/

// HERE i-1 j=n-1
int solve(vector<vector<int>> &t,int arr[],int i,int j){
        if(i>=j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int min_cost=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp_ans=solve(t,arr,i,k)+solve(t,arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            if(temp_ans<min_cost){
                min_cost=temp_ans;
            }
        }
        return t[i][j]=min_cost;
    }
int matrixMultiplication(int n, int arr[]){
    // code here
    vector<vector<int>> t(n+1,vector<int>(n+1,-1));
    return solve(t,arr,1,n-1);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<matrixMultiplication(n,a);
    return 0;
}