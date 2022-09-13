#include<bits/stdc++.h>
using namespace std;

// Time Complexity O(n)
// Space Complexity O(n)
int fib(int n,int t[]){ // Memoization / Top Down Approach
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(t[n]!=-1){
        return t[n];
    }
    int a;
    int b;
    if(t[n-1]==-1){
        a=fib(n-1,t);
        t[n-1]=a;
    }else{
        a=t[n-1];
    }
    if(t[n-2]==-1){
        b=fib(n-2,t);
        t[n-2]=b;
    }else{
        b=t[n-2];
    }
    return t[n]=a+b;
}

int fibb(int n){ // bottom up approach
    if(n<2){
        return n;
    }
    int t[n+1];
    t[0]=0;
    t[1]=1;
    for(int i=2;i<=n;i++){ 
        t[i]=t[i-1]+t[i-2];
    }
    return t[n];   
}

// Highly Optimized Solution
// Time Complexity O(n)
// Optimized Space Complexity O(1)
/* 
    a,b,c;
    next step
    c=a+b
    a=b; // these store the prev results
    b=c;

*/
int fibbb(int n){
        if(n<2){
            return n;
        }
        int a=0,b=1;
        int c;
        for(int i=2;i<=n;i++){ 
            c=a+b;
            a=b;
            b=c;
        }
        return c; 
    }
int main(){
    int n;
    cin>>n;
    int t[n+1];
    cout<<fib(n,t);
    return 0;
}