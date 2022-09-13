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
vector<int> factorize(int no,vector<int> &primes){
    vector<int> factors;
    for(int i = 0; primes[i]*primes[i]<=no; i++){
        if(no%primes[i]==0){
            factors.push_back(primes[i]);
            while(no%primes[i]==0){
                no=no/primes[i];
            }
        }
    }
    if(no!=1){ // it means it is a prime number
        factors.push_back(no);
    }
    cout<<endl;
    return factors;
}

// concept : eg 12=2^a 3^b the number of divisors : ans-> (a+1)(b+1)  
int no_of_divisors(int no,vector<int> &primes){
    int ans=1;
    vector<int> factors;
    for(int i = 0; primes[i]*primes[i]<=no; i++){
        if(no%primes[i]==0){
            int cnt=0;
            factors.push_back(primes[i]);
            while(no%primes[i]==0){
                cnt++;
                no=no/primes[i];
            }
            ans*=(cnt+1);
            //
        }
    }
    if(no!=1){ // it means it is a prime number
        ans=ans*2;
        factors.push_back(no);
    }
    return ans;
}

// concept : eg 12=2^a 3^b the number of divisors : ans-> (2^(a+1)-1)/(2-1) * (3^(b+1)-1)/(3-1)  
int sum_of_divisors(int no,vector<int> &primes){
    ll int num=no;
    ll int ans=1;
    vector<int> factors;
    for(int i = 0; primes[i]*primes[i]<=no; i++){
        if(no%primes[i]==0){
            ll int temp=1;
            factors.push_back(primes[i]);
            while(no%primes[i]==0){
                temp*=primes[i];
                no=no/primes[i];
            }
            temp=((temp*primes[i])-1)/(primes[i]-1);
            ans*=temp;
        }
    }
    if(no!=1){ // it means it is a prime number
        ans*=((no*no)-1)/(no-1); 
        factors.push_back(no);
    }
    return ans;
}

int main(){
    long long int n=100000;
    bool* p=new bool[n+1]{0};
    vector<int> primes=prime_sieve(p,1000);
    int t;
    cin>>t;
    while(t--){

        int no;
        cin>>no;

        vector<int> factors=factorize(no,primes);
        for(auto f:factors){
            cout<<f<<" ";
        }
        cout<<endl;

        int divisors=no_of_divisors(no,primes);
        cout<<"number of divisors : "<<divisors<<endl;

        int sum=sum_of_divisors(no,primes);
        cout<<"sum of factors : "<<sum<<endl;

    }
    return 0;
}