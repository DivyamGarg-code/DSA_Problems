// RECURSIVE APPROACH
// Best case O(1)
// Worst case O(logn) after each time search space is becoming half
#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[],int data,int start,int end){
    if(start<=end){
        int mid=start+(end-start)/2;
        if(a[mid]==data){
            return mid;
        }
        if(data<a[mid]){
            return binary_search(a,data,start,mid-1);
        }
        if(data>a[mid]){
            return binary_search(a,data,mid+1,end);
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"enter the size of array : ";
    cin>>n;
    int a[n];
    cout<<"enter the number of elements\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cout<<"enter the data you want to search : ";
    cin>>key;
    int s=0;
    int e=n-1;
    cout<<binary_search(a,key,s,e);
    return 0;
}