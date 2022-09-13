#include<bits/stdc++.h>
using namespace std;

// memoization 
int knapsack(int weight[],int price[],int t[][8],int capacity,int n){
    if(n==0 || capacity==0){
        return 0;
    }
    if(t[n][capacity]!=-1){
        return t[n][capacity];
    }
    if(weight[n-1]<=capacity){
        return t[n][capacity]=max((price[n-1]+knapsack(weight,price,t,capacity-weight[n-1],n-1)),knapsack(weight,price,t,capacity,n-1));
    }else{
        return t[n][capacity]=knapsack(weight,price,t,capacity,n-1);
    }
}
int main(){
    int weight[]={1,3,4,5};
    int price[]={1,4,5,7};
    int t[5][8];
    memset(t,-1,sizeof(t));
    cout<<knapsack(weight,price,t,7,4);
    return 0;
}