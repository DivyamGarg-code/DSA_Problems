#include<bits/stdc++.h>
using namespace std;

long long int decimalToBinary(int n){
    long long int p=1;
    long long int ans=0;
    while(n>0){
        int lastBit=n&1;
        ans+=p*lastBit;
        p*=10;
        n=n>>1;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<decimalToBinary(n);
    return 0;
}