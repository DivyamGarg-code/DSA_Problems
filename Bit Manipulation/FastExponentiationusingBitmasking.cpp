#include<bits/stdc++.h>
using namespace std;

// Exponentiation/Power using Bitmasking
// Reducing the TC from O(N) to O(logn) as their are are max logn bits in a no. therefore this much time we need to iterations
int power_optimised(int a,int n){
    int ans=1;
    while(n>0){
        int last_bit=n&1;
        if(last_bit==1){
            ans=ans*a;
        }
        a=a*a; // square up
        n=n>>1; // discard the last bit of N
    }
    return ans;
}
int main(){
    int a,n;
    cin>>a>>n;
    cout<<power_optimised(a,n);
    return 0;
}