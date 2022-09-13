// SIMPLE LOOP

#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[],int size,int key){
    int s=0,e=size-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==key){
            return mid;
        }else if(a[mid]>key){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"enter the size of array : ";
    cin>>n;
    int a[n];
    cout<<"enter the elements\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cout<<"enter the key : ";
    cin>>key;
    cout<<binary_search(a,n,key);
    return 0;
}