#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Native approach O(n)
// O (n*n) for n numbers
bool isPrime1(int n){
    if(n==1){
        return false;
    }
    if(n==2){
        return true;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

// Native approach O(sqrt(n)) for 1 number
// O (n*sqrt(n)) for n numbers
bool isPrime2(int n){
    if(n==1){
        return false;
    }
    if(n==2){
        return true;
    }
    for(int i=2;i*i<=n;i++){ 
        if(n%i==0){
            return false;
        }
    }
    return true;
}

// Sieve Approach - Generate a array containing prime numbers 
// n/2 + n/3 + n/5 .... takes approx log(logn)  
//  Time complexity : O(nlog(logn)) approximately linear : for n numbers
void prime_sieve(int p[],int n){

    // first mark all the odd numbers prime : n/2 iterations 
    for(int i = 3; i <=n; i+=2){
        p[i]=1;
    }
    //Sieve
    for(ll i=3;i<=n;i+=2){  
        // if the current number is not marked (it is prime)
        if(p[i]==1){
            // mark all the multiples of i as not prime
            for(ll j=i*i;j<=n;j=j+i){
                p[j]=0;
            }
        }
    }
    // special case
    p[2]=1;
    p[1]=p[0]=0;
}

int main(){
    int n;
    cin>>n;
    int p[n+1]={0};
    prime_sieve(p,n);
    // let's print prime upto range n
    for(int i=0;i<=n;i++){
        if(p[i]==1){
            cout<<i<<" ";
        }
    }
    return 0;
}