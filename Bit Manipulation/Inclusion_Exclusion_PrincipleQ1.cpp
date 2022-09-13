#include<bits/stdc++.h>
using namespace std;
/*
    Inclusion Exclusion Principle
    How many numbers are there <1000 such that they are divisible by either 2,3,or 5 
    basically you have to take union |2 U 3 U 5|
*/

int combination(int a[],int n){
    int j=0;
    int cmb=1;
    int p=1;
    int cnt=0;
    while(n>0){
        int last_bit=(n&1);
        if(last_bit==1){
            cmb=cmb*a[j];
            cnt++;
        }
        n=n>>1;
        j++;
    }
    int ans=999/cmb;
    if(cnt%2==0){
        return ans*(-1);
    }
    return ans;
}
void printAns(int a[],int n){
    int ans=0;
    for(int i = 1; i < (1<<n); i++){ // for total number of combinations
        ans+=combination(a,i);
    }
    cout<<ans;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    printAns(a,n);
    
    return 0;
}

