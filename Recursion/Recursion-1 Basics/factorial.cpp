#include<bits/stdc++.h>
using namespace std;
int fact(int n){
    // Base case 
    if(n==0){
        return 1;
    }
    // recursive case
    return n*fact(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}