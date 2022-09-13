// Binary_Search : First and Last occurance of an element
// eg 1 2 5 8 8 8 8 8 10 12 15 20  key=8  first occur:3 last_occur:7
#include <bits/stdc++.h>
using namespace std; 
int first_occurance(int a[],int n,int data){
    int start=0;
    int end=n-1;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(a[mid]==data){
            // To get the first occurance of that element do 2 things
            ans=mid;
            end=mid-1;
        }
        if(data<a[mid]){
            end=mid-1;
        }
        if(data>a[mid]){
            start=mid+1;
        }
    }
    return ans;
}

int last_occurance(int a[],int n,int data){
    int start=0;
    int end=n-1;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(a[mid]==data){
            // To get the first occurance of that element do 2 things
            ans=mid;
            start=mid+1;
        }
        if(data<a[mid]){
            end=mid-1;
        }
        if(data>a[mid]){
            start=mid+1;
        }
    }
    return ans;
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
    cout<<first_occurance(a,n,key)<<endl;
    cout<<last_occurance(a,n,key)<<endl;
    return 0;
}