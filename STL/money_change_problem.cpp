#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b){ // as we need number less than equal to money
    return a<=b;
}
int main(){
    // Indian money change
    int coins[]={1,2,5,10,20,50,100,200,500,2000};
    int sum=0;
    int n=sizeof(coins)/sizeof(coins[0]);
    int money;
    cin>>money;
    //cout<<lower_bound(coins,coins+n,money,compare)-coins-1;
    while(money>0){
        int lb=lower_bound(coins,coins+n,money,compare)-coins-1;
        int c=money/coins[lb];
        sum+=c;
        cout<<"Rs "<<coins[lb]<<" "<<c<<endl;
        money=money-c*coins[lb];
    }
    cout<<"Final sum of coins "<<sum;
    return 0;
}     