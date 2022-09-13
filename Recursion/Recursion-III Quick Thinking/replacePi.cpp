#include<bits/stdc++.h>
using namespace std;
// Replace pi with 3.14
// given a string -> xpighpilmpipi -> x3.14gh3.14lm3.14 

void replace(char a[],int n){
    if(n==1 || n==0){
        return;
    }
    if(a[0]=='p' && a[1]=='i'){
        a[0]='3';
        a[1]='.';
        for(int i =n-1; i>1; i--){
            a[i+2]=a[i];
        }
        a[2]='1';
        a[3]='4';
        return replace(a+4,n-2); // we moved by 4 positions ie after 3.14
    }else{
        return replace(a+1,n-1);
    }
    
}


int main(){
    char a[100]="xpighpilmpip";
    int n=strlen(a);
    replace(a,n);
    int k=strlen(a);
    for(int i = 0; i <k; i++){
        cout<<a[i];
    }
    return 0;
}