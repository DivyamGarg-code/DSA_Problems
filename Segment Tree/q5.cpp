#include<bits/stdc++.h>
using namespace std;

// Bank Transactions
// basically you need to find the maximum number of transactions in which we can skip that transaction in which the net balance can become negative

// int countTransactions(int a[],int n,int i=0,int sum=0){
//     if(i>=n){
//         return 0;
//     }
//     int include=INT_MIN,exclude=INT_MIN;
//     if(a[i]>=0){
//         return 1+countTransactions(a,n,i+1,sum+a[i]);
//     }
//     if((sum+a[i])<0){
//         return countTransactions(a,n,i+1,sum);
//     }
//     // case in which a[i]<0 and (sum+a[i])>=0
//     // we can take or skip 
//     return max(1+countTransactions(a,n,i+1,sum+a[i]),countTransactions(a,n,i+1,sum));
// }

int countTransactions(int a[],vector<vector<int>> &dp,int n,int i=0,int sum=0){
    if(i>=n){
        return 0;
    }
    
    if(a[i]>=0){
        return 1+countTransactions(a,dp,n,i+1,sum+a[i]);
    }
    if((sum+a[i])<0){
        return countTransactions(a,dp,n,i+1,sum);
    }
    // case in which a[i]<0 and (sum+a[i])>=0
    // we can take or skip 
    return max(1+countTransactions(a,dp,n,i+1,sum+a[i]),countTransactions(a,dp,n,i+1,sum));
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            sum+=arr[i];
        }
    }
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    cout<<countTransactions(arr,n);
    return 0;
}