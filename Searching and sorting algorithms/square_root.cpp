// SQUARE ROOT OF A NUMBER USING BINARY SEARCH
// Time complexity (log(n)+ no. of decimal places) : log(n)+precision(which is mostly goes upto 8)
// TC : log(n)+p
#include <bits/stdc++.h>
using namespace std; 

float square_root(int n,int dec){
    int s=0;
    int e=n;
    float ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(mid*mid==n){
            return mid;
        }else if(mid*mid<n){
            ans=mid;
            s=mid+1;
        }else if(mid*mid>n){
            e=mid-1;
        }
    }

    // floating part
    // brute force
    float inc=0.1;
    for(int i = 1; i <=dec; i++){
        while(ans*ans<=n){
            ans=ans+inc;
        }
        // overshoot the value
        ans=ans-inc;
        inc=inc/10;
    }
    return ans;
}

int main(){
    int key;
    cout<<"enter the data whose square root you want to find : ";
    cin>>key;
    cout<<square_root(key,3);
    return 0;
}