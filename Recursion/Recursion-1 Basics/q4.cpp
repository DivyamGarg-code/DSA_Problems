#include<bits/stdc++.h>
using namespace std;
// Write a recursive function to check if array is sorted or not 
bool isSorted(int a[],int n){
    // Base case
    if(n==0 || n==1){
        return true;
    }
    // recursive call
    if(a[0]<=a[1] && isSorted(a+1,n-1)){
        return true;
    }
    return false;
}

int binary_search(int a[],int s,int e,int key){ // return the index
    // base case
    if(s>e){
        return -1;
    }
    int mid=s+(e-s)/2;
    if(a[mid]==key){
        return mid;
    }else if(a[mid]<key){
        binary_search(a,mid+1,e,key);
    }else{
        binary_search(a,s,mid-1,key);
    }
}
int power(int a,int b){
    if(b==0){
        return 1;
    }
    return a*power(a,b-1);
}

int multiply(int a,int b){
    if(b==0){
        return 0;
    }
    return a+multiply(a,b-1);
}

int main(){
    int a[]={10,20,30,40,50,60,70};
    int n=sizeof(a)/sizeof(a[0]);
    int s=0;
    int e=n-1;
    // int key;
    // cin>>key;
    // cout<<binary_search(a,s,e,key);
    int d,b;
    cin>>d>>b;
    cout<<power(d,b)<<endl;
    cout<<multiply(d,b)<<endl;
    return 0;
}