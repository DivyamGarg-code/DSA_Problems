// Binary_Search in the rotated sorted array
#include <bits/stdc++.h>
using namespace std; 

int find(int a[],int n,int data){
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(data==a[mid]){
            return mid;
        }else if(a[s]<=a[mid]){ // if the mid lies in part 1
            // 2 cases-> element lies on the left or right of the mid
            // left of mid part will be sorted and rt part will be unsorted
            if(data>=a[s] && data<=a[mid]){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }else if(a[mid]<=a[e]){ // if the mid lies in part 2 
            if(data>=a[mid] && data<=a[e]){
                s=mid+1;
            }else{
                e=mid-1;
            }
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
    cout<<find(a,n,key)<<endl;
    return 0;
}