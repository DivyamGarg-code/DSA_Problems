#include<bits/stdc++.h>
using namespace std;

// given a sorted array ,find the pair of elements that sum to K(given)
int main(){
    int n,left,right,sum;
    cin>>n;
    int l=0;
    int r=n-1;
    int *a=new int[n];
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    int k;
    cout<<"Enter number whose pair you want to find : ";
    cin>>k;
    while(l<r){
        left=a[l];
        right=a[r];
        sum=left+right;
        if(sum>k){
            r-=1;
        }else if(sum<k){
            l+=1;
        }else{
            cout<<"Pair exist : ("<<left<<","<<right<<")";
            return 0;
        }
    }
    cout<<"Pair does'nt exist";
}