#include<bits/stdc++.h>
using namespace std;
// Unique number II  tYPE :  2n+2 
//Example a=[1,1,2,3,5,2,5,7]
// Unique = 3,7
// linear time , constant space

int IstSetBitPos(int n){
    int i=0;
    while(n>0){
        int lastBit=n&1;
        if(lastBit==1){
            break;
        }
        i++;
        n=n>>1;
    }
    return i;
}
int get_ith_Bit(int data,int i){
    int mask=1<<i;
    int bit=(data&mask)>0?1:0;
    return bit;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int result=0;
    for(int i = 0; i < n; i++){
        result=result^a[i];
    }
    // this number can't be 0 as it will give the XOR of 2 unique numbers present in the array
    // therfore have atleast 1 setbit Finding the position of 1st set bit
    int j=IstSetBitPos(result);
    int temp=0;
    for(int i = 0; i < n; i++){
        if(get_ith_Bit(a[i],j)==1){ 
            temp=temp^a[i]; // 5^5^7 will give 7 at the end
        }
        
    }
    int b=temp^result;
    cout<<temp<<" "<<b;
    return 0;
}