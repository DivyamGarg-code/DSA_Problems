#include<bits/stdc++.h>
using namespace std;

// Greatest Common Divisor using Euclid's Algorithm
// TIME COMPLEXITY : O(log(min(a, b))
int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
    // or  return b==0?a:gcd(b,a%b);
    
}

// We can find the lcm by the formula ie lcm * gcd = a * b 
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}