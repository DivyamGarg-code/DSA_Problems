#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n){
    return (n&1);
}

int getBit(int n,int i){
    int mask= 1<<i;
    int bit=(n&mask)>0?1:0;
    return bit;
}

int setBit(int n,int i){ // when the bit is 0 and you have to change to 1
    int mask= 1<<i;
    int bit= n|mask; 
    return bit;
}

int clearBit(int &n,int i){ // when the bit is 1 and you have to change to 0
    int mask= ~(1<<i);
    n=n&mask;
    return n;
}

void updateBit(int &n,int i,int v){
    int mask= ~(1<<i);
    int cleared_n=n&mask;
    n= cleared_n|(v<<i);
}

int clearLast_I_Bits(int n,int i){ // i  is the number of bits getting cleared
    int mask=(-1<<i);
    return n&mask;
}

int clearRange_I_to_J(int n,int i,int j){
    int ones=(~0);
    int a=ones<<(j+1);
    int b=(1<<i)-1;
    int mask=a|b;
    return n&mask;
}

int Range_I_to_J(int n,int i,int j){ // same as above 
    int a=(-1)<<(j+1);
    int b=~(-1<<i);
    int mask=a|b;
    return n&mask;
}

int replace_bits(int n,int m,int i,int j){
    int N=clearRange_I_to_J(n,i,j);
    int mask=m<<i;
    return N|mask;

}

int main(){
    
    cout<<clearRange_I_to_J(6667,1,3)<<endl;
    cout<<Range_I_to_J(6667,1,3)<<endl;
    return 0;
}