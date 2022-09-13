#include<bits/stdc++.h>
using namespace std;

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 Maximum Sum of non adjacent elements in a circular array
*/

// Reccursive code
int f(int a[],int i){     
    if(i<0){
        return 0;
    }
    int pick=a[i]+f(a,i-2);
    int not_pick=f(a,i-1);
    return max(pick,not_pick);
}
int house_robbery(int a[],int n){
    int b[n-1];
    int c[n-1];
    for(int i=0;i<n-1;i++){
        b[i]=a[i];
    }
    for(int i=0;i<n-1;i++){
        c[i]=a[i+1];
    }
    for(int i=0;i<n-1;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n-1;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    cout<<f(b,n-2)<<" "<<f(c,n-2)<<endl;
    return max(f(b,n-2),f(c,n-2));
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<house_robbery(a,n);
    return 0;
}