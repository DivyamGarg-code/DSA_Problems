#include<bits/stdc++.h>
using namespace std;

int f(int n){
    if(n<=0){
        return 0;
    }
    if(n==1){
        return 2;
    }
    if(n==2){
        return 3;
    }
    return f(n-1)+f(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}