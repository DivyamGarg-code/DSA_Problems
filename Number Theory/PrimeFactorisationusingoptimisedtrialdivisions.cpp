#include<bits/stdc++.h>
using namespace std;
// Prime factorization of number
// 2. Optimised 
void primefactors(int n){
    vector<pair<int,int>> factors;
    for(int i = 2; i*i<=n; i++){
        if(n%i==0){
            // keep on dividing by i till it is divisible
            int cnt=0;
            while(n%i==0){
                cnt++;
                n=n/i;
            }
            factors.push_back(make_pair(i,cnt));
        }
    }
    if(n!=1){ // whatever is left is a prime number itself
        factors.push_back(make_pair(n,1));
    }
    // print the factors
    for(auto p:factors){
        cout<<p.first<<" "<<p.second<<endl;
    }
    
}



int main(){
    int n;
    cin>>n;
    primefactors(n);
    return 0;
}