/*
Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is 
to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t<=10). In each of
the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) 
separated by a space.

Output
For every test case print all prime numbers p such that m <= p <= n, one number per 
line, test cases separated by an empty line.
*/
#include<bits/stdc++.h>
using namespace std;

const long long n=100000;
bitset<100005> b;
vector<int> primes;
void sieve(){
    b.set(); //considering all numbers prime
    b[0]=b[1]=0;
    primes.reserve(n+1);
    for(long long int i = 2; i <=n; i++){
        if(b[i]==1){
            primes.push_back(i);
            for(long long int j = i*i; j <=n; j=j+i){
                b[j]=0;
            }
        }
    }
}



int main(){
    sieve();
    // t test cases not written
    long long int n,m;
    cin>>m>>n;
    bool segment[n-m+1]; // assuming all numbers to be prime;
    for(long long int i = 0; i <= n-m; i++){
        segment[i]=1;
    }
    cout<<endl;
    for(auto x:primes){
        cout<<"x : "<<x<<endl;
        if(x*(long long)x>n){
            cout<<"Break "<<endl;
            break;
        }
        long long int start=(m/x)*x;
        if(x*x>m){
            start=x*x; 
        }else if(x>=m && x<=n){
            start=2*x;
        }
        cout<<"Marking ";
        for(long long int i = start; i <=n; i+=x){
            cout<<i<<" ";
            segment[i-m]=0; // mark the factors of prime no. x as not primes
        }
        cout<<" as not prime"<<endl;
    }
    for(long long int i = m; i <= n; i++){
        if(segment[i-m]==1 && i!=1){
            cout<<i<<" ";
        }
    }
    
    

    return 0;
}