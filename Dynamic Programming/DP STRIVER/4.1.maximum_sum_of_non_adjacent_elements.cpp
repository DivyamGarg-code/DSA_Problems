#include<bits/stdc++.h>
using namespace std;

/*
Maximum Sum of non adjacent elements ie non adjecdent indeces elements
*/
// Reccursive code
// int f(int a[],int i){     
//     if(i<0){
//         return 0;
//     }
//     int pick=a[i]+f(a,i-2);
//     int not_pick=f(a,i-1);
//     return max(pick,not_pick);
// }
// For this call cout<<f(a,n-1);

// Tabulation
// int f(int a[],int n){
//     int dp[n];
//     for(int i=0;i<n;i++){
//         if(i==0){
//             dp[i]=a[i];
//         }else{
//             int pick,not_pick;
//             if(i-2>=0){
//                 pick=a[i]+dp[i-2];
//             }else{
//                 pick=a[i];
//             }
//             if(i-1>=0){
//                 not_pick=dp[i-1];
//             }else{
//                 not_pick=0;
//             }
//             dp[i]=max(pick,not_pick);
//         }
//     }
//     return dp[n-1];
// }

//Tabulation + Space Optimization
int f(int a[],int n){
    if(n==1){
        return a[0];
    }
    if(n==2){
        return max(a[0],a[1]);
    }
    int prev=a[0],prev1=max(a[0],a[1]),curr; // [prev,prev1,curr]
    for(int i=2;i<n;i++){
        int pick,not_pick;
        if(i-2>=0){
            pick=a[i]+prev;
        }else{
            pick=a[i];
        }
        if(i-1>=0){
            not_pick=prev1;
        }else{
            not_pick=0;
        }
        curr=max(pick,not_pick);
        prev=prev1;
        prev1=curr;
    }
    return curr;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<f(a,n);
    return 0;
}