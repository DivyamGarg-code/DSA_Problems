// Space optimised Sieve using Bitset;
/*
A bitset is an array of bool but each Boolean value is not stored separately instead 
bitset optimizes the space such that each bool takes 1 bit space only, so space taken 
by bitset bs is less than that of bool bs[N] and vector bs(N). However, a limitation of 
bitset is, N must be known at compile time, i.e., a constant (this limitation is not 
there with vector and dynamic array)
*/

// Checking if the large number is prime or not
#include<bits/stdc++.h>
using namespace std;
// global declaration
const long long int n=10000000;
bitset<10000005> b;  // could be done in O(1) time if you have done the pre computation
vector<int> primes;

void sieve(){
    // set all the bits
    b.set(); // 1,1,1,1,....
    b[0]=b[1]=0;
    for(long long int i = 2; i <= n; i++){
        if(b[i]==1){
            primes.push_back(i);
            for(long long int j =i*i; j <=n; j=j+i){
                b[j]=0;
            }
        }
    }
}

bool isPrime(long long num){
    if(num<=n){
        return (b[num]==1)?true:false; // This will take O(1) time 
    }else{
        for(long long int i = 0; primes[i]*(long long)primes[i]<=num; i++){
            if(num%primes[i]==0){
                return false;
            }
        }
        return true;
    }
}



int main(){
    sieve();
    if(isPrime(2147483647)){
        cout<<"Yes it is";
    }else{
        cout<<"False";
    }
    return 0;
}