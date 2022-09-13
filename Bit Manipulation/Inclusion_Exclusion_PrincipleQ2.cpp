#include<bits/stdc++.h>
using namespace std;
/*
After the release of Avengers, Ironman and Thor got into a fight and Ironman challenged Thor to find out the number of numbers between 1 and n 
which are divisible by any of the prime numbers less than 20. Ironman being great at maths quickly answered the question but then Thor 
asked him to write a program for it. Ironman however found it quite difficult as he did not wanted to write so many lines of code. he knows
 that you are smart and can code this up easily. Can you do it?
*/

int combination(int a[],int n,int x){
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
    int ans=x/cmb;
    if(cnt%2==0){
        return ans*(-1);
    }
    return ans;
}
void printAns(int a[],int size,int x){
    int ans=0;
    for(int i = 1; i < (1<<size); i++){ // for total number of combinations
        ans+=combination(a,i,x);
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int j = 0; j < t; j++){
        int n;
        cin>>n;
        int a[]={2,3,5,7,11,13,17,19};
        printAns(a,8,n); // here 8 is the size of array
    }
    return 0;
}

