#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    // Base case 
    if(n==0 || n==1){
        return 1;
    }
    // recursive case
    int f1=fib(n-1);
    int f2=fib(n-2);
    return f1+f2;
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}