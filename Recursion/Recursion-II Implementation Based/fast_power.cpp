#include<bits/stdc++.h>
using namespace std;
int power(int a,int n){ // Time complexity O(n)
    if(n==0){
        return 1;
    }
    return a*power(a,n-1);
}


int fast_power(int a,int n){ // Time complexity O(logn)
    if(n==0){
        return 1;
    }
    // rec case
    int smaller_ans=fast_power(a,n/2);
    smaller_ans*=smaller_ans;
    if(n&1){ // if n is odd 
        return a*smaller_ans;
    }
    return smaller_ans;
    
}
int main(){
    int a,n;
    cin>>a>>n;
    cout<<fast_power(a,n);
    return 0;
}