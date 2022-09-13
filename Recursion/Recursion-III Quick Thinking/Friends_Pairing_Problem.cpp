#include<bits/stdc++.h>
using namespace std;
// Friends Pairing Problem
// Given N friends who want to go to a party on bikes.Each guy can go as a single or as a couple.
// Find the number of ways in which N friends ca go to the party
int f(int n){
    if(n<0){
        return 0;
    }
    if(n==0 || n==1){
        return 1;
    }
    return f(n-1)+(n-1)*f(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}