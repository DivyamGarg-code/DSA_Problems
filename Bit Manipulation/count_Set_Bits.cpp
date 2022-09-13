#include<bits/stdc++.h>
using namespace std;

// 1st method  
// Time complexity (log(n)+1) int 
int countBits(int n){
    int ans=0;
    while(n>0){
        ans+=(n&1);
        n=n>>1;
    }
    return ans;
}

// 2nd method
// TC O(number of set bits) in the worst case number of set bits can go upto log(n) when all the bits are 1
int countBitsFast(int n){
    int ans=0;
    while(n>0){
        n=n&(n-1);
        ans+=1;
    }
    return ans;
}

// 3rd method
// STL __built_in_popcount
int main(){
    // Given a number n Find the numberr of set bits in the binary representation of it
    // N=13 , Binary=1101
    int n;
    cin>>n;
    cout<<countBits(n)<<endl;
    cout<<countBitsFast(n)<<endl;
    cout<<__builtin_popcount(n)<<endl;
    return 0;
}