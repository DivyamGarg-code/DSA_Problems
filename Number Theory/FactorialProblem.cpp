/*
 Find the minimum value of x such that n!%k^x = 0
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Sieve Approach - Generate a array containing prime numbers 
// n/2 + n/3 + n/5 .... takes approx log(logn)  
//  Time complexity : O(nlog(logn)) approximately linear : for n numbers
vector<int> prime_sieve(bool p[],int n){
    vector<int> primes;
    primes.push_back(2);
    // first mark all the odd numbers prime : n/2 iterations 
    for(long long int i = 3; i <=n; i+=2){
        p[i]=1;
    }
    //Sieve
    for(long long int i=3;i<=n;i+=2){  
        // if the current number is not marked (it is prime)
        if(p[i]==1){
            primes.push_back(i);
            // mark all the multiples of i as not prime
            for(long long int j=i*i;j<=n;j=j+i){
                p[j]=0;
            }
        }
    }
    // special case
    p[2]=1;
    p[1]=p[0]=0;

    return primes;
}

// This returns the vector of prime factors
vector<pair<int,int>> factorize(int no,vector<int> &primes){
    vector<pair<int,int>> factors;
    for(int i = 0; primes[i]*primes[i]<=no; i++){
        if(no%primes[i]==0){
            int cnt=0;
            while(no%primes[i]==0){
                cnt++;
                no=no/primes[i];
            }
            factors.push_back(make_pair(primes[i],cnt));
        }
    }
    if(no!=1){  // whatever is left is a prime number itself
        factors.push_back(make_pair(no,1));
    }
    return factors;
    
}

int fact(int n,int p){
    int c=0;
    int j=p;
    while(j<=n){
        int cnt=n/j;
        c+=cnt;
        j=j*p;
    }
    return c;
}

int main(){
    long long int n=100000;
    bool* p=new bool[n+1]{0};
    vector<int> primes=prime_sieve(p,1000);
    int t;
    cin>>t;
    while(t--){

        int n,p;
        cin>>n>>p;
        int x=INT_MAX;
        vector<pair<int,int>> factors=factorize(p,primes);
        for(auto f:factors){ // This will give the prime factors of p and k= cnt of that prime factor
            int p=f.first; 
            int k=f.second;
            int c=fact(n,p); // Finding the power of p in n!
            int d=c/k;
            cout<<"p :"<<p<<" c : "<<c<<" k : "<<k<<" c/k : "<<d<<endl;
            x=min(x,d);
            if(x==0){ // ie we are not able to find a factor in n so that p could be divisible
                break;
            }
        }
        cout<<"x -> "<<x<<endl;
    }
    return 0;
}