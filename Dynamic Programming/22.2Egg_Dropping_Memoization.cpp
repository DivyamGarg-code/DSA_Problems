#include<bits/stdc++.h>
using namespace std;

/*
https://www.youtube.com/watch?v=S49zeUjeUL0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=42

Egg Dropping using Recursion
Problem statement: You are given N floor and K eggs. You have to minimize the number of times you have to drop the eggs to find the critical floor where critical floor means the floor beyond which eggs start to break. Assumptions of the problem:

If egg breaks at ith floor then it also breaks at all greater floors.
If egg does not break at ith floor then it does not break at all lower floors.
Unbroken egg can be used again.
Note: You have to find minimum trials required to find the critical floor not the critical floor.

Input:
N = 1, K = 2(floors)
Output: 2
Explanation: 
1. Drop the egg from floor 1. If it 
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.

We have to find the minimum number of attemps it would take to find the threshold floor in the worst case

*/
int t[11][100002];
int solve(int e,int f){
    if(f==0 || f==1){
        return f;
    }
    if(e==1){ // if eggs=1 ie we have to check all the f floors one by one
        return f;
    }
    if(t[e][f]!=-1){
        return t[e][f];
    }
    int min_attempts=INT_MAX;
    for(int k=1;k<=f;k++){
        int low,high;
        if(t[e-1][k-1]!=-1){
            low=t[e-1][k-1];
        }else{
            low=solve(e-1,k-1);
            t[e-1][k-1]=low;
        }
        if(t[e][f-k]!=-1){
            high=t[e][f-k];
        }else{
            high=solve(e,f-k);
            t[e][f-k]=high;
        }
        int temp=1+max(low,high);
        min_attempts=min(min_attempts,temp);
    }
    return t[e][f]=min_attempts;
}
int main(){
    memset(t,-1,sizeof(t));
    int eggs,floor;
    cin>>eggs>>floor;
    cout<<solve(eggs,floor);
    return 0;
}