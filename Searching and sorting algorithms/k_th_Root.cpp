// kth ROOT OF A NUMBER USING BINARY SEARCH
// Time complexity (log(n)+ no. of decimal places) : log(n)+precision(which is mostly goes upto 8)
// TC : log(n)+p
#include <bits/stdc++.h>
using namespace std; 

bool isPossible(long long int n,long double ans,long long int k){
    long double t=ans;
    for(long long int i = 1; i < k; i++){
        t=t*ans;
        if(t>n){
            return false;
        }
    }
    return true;
}
float kth_root(long long int n,long long int k,long long dec){
    long long int s=0;
    long long int e=n;
    float ans=-1;
    while(s<=e){
        long long int mid=s+(e-s)/2;
        long long int temp=mid;
        long long int flag=0;
        for(long long int i = 1; i < k; i++){
            temp=temp*mid;
            if(temp>n){
                e=mid-1;
                flag=1;
                break;
            }
        }
        if(flag!=1){
            if(temp==n){
                return mid;
            }else{
                ans=mid;
                s=mid+1;
            }
        }
        
    }
    // fraction part
    long double inc=0.1;
    
    for(int i=1;i<=dec;i++){
        while(isPossible(n,ans,k)){
            ans=ans+inc;
        }
        ans=ans-inc;
        inc=inc/10.0;

    }


    return ans;

    
}

int main(){
    long long int n,k,d;
    cout<<"enter the data whose k_th root you want to find along with the number of decimals: ";
    cin>>n>>k>>d;
    cout<<kth_root(n,k,d);
    // for example cube root of 28 : Enter 28 3 4->number of decimal places
    // time complexity k*log(n)
    return 0;
}