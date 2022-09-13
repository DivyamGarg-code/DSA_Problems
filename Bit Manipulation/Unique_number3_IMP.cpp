#include<bits/stdc++.h>
using namespace std;

// Unique Number III Type 3N+1
// Time complexity O(64*n) ie O(n)
// Space complecxity


// find the sum of the bits of all the numbers at 1st,2nd 3rd..position and so on and check the sum is it of the form 3n or 3n+1
//  which will give methe bit of unique number either o or 1
int get_ith_Bit(int data,int i){
    int mask=1<<i;
    int bit=(data&mask)>0?1:0;
    return bit;
}

int countBits(int n){
    int a=log(n)/log(2);
    return a+1;
}

int main(){
    int n;
    cin>>n;
    int a[64]={0};
    int ans=0;
    int p=1;
    int max_element=0;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        max_element=max(max_element,x);
        int N=countBits(x);
        for(int i = 0; i < N; i++){
            a[i]+=get_ith_Bit(x,i);
            a[i]=a[i]%3;
        }
    }
    int cnt_bits_max=countBits(max_element);
    for(int i = 0; i < cnt_bits_max; i++){
        ans+=(a[i]*p);
        p=p*2;
    }
    cout<<ans;
    return 0;
}

/*  OR 
    // Array of fixed size always counted as constant size O(1) as it does'not depending upon n
    int cnt[64]={0};

    int n,no;
    cin>>n;

    for(int i=0;i<n;i++){
        int j=0;
        cin>>no;
        // Update the cnt by extracting the bits from last
        while(no>0){
            int last_bit=no&1;
            cnt[j]+=last_bit;
            no=no>>1;
        }
    }

    // Iterate over the array and form the answer by converting 0's and 1's into a number
    int p=1;
    int ans=0;
    for(int i=0;i<64;i++){
        cnt[i]%=3;
        ans+=(cnt[i]*p);
        p=p<<1;
    }
*/ 