#include<bits/stdc++.h>
using namespace std;
/*
Recursive Solution || Time complexity exponential
int f(int i,int h[]){
    if(i==0){
        return 0;
    }
    int a,b;
    a=f(i-1,h)+abs(h[i]-h[i-1]);
    if(i>1){
        b=f(i-2,h)+abs(h[i]-h[i-2]);
    }else{
        b=INT_MAX;
    }
    return min(a,b);
}

Tabulation/Bottom Up 
Time and Space Compexity O(n)
int f(int n,int h[]){
    int dp[n];
    for(int i=0;i<n;i++){
        if(i==0){
            dp[i]=0;
        }else{
            int a,b;
            a=dp[i-1]+abs(h[i]-h[i-1]);
            if(i>1){
                b=dp[i-2]+abs(h[i]-h[i-2]);
            }else{
                b=INT_MAX;
            }
            dp[i]=min(a,b);
        }
    }
    return dp[n-1];
}

*/

// TC O(n) SC O(1) using 3 variables
int f(int n,int h[]){
    if(n==0){
        return 0;
    }
    if(n==1){
        return abs(h[1]-h[0]);
    }
    int prev1=0,prev2=abs(h[1]-h[0]);
    int curr;
    for(int i=2;i<n;i++){
        int a,b;
        a=prev2+abs(h[i]-h[i-1]);
        if(i>1){
            b=prev1+abs(h[i]-h[i-2]);
        }else{
            b=INT_MAX;
        }
        curr=min(a,b);
        prev1=prev2;
        prev2=curr;
    }
    return curr;
}

int main(){
    int n;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    cout<<f(n-1,h);
    return 0;
}