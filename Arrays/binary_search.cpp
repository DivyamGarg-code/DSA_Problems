// Binary Search : Only applicable on sorted array Time complexity O(logn) 
#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[],int n,int key){
    int s=0;
    int e=n-1;
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
    int n,key;
    cout<<"Enter the size of array\n";
    cin>>n;
    int *a=new int[n];
    cout<<"Enter "<<n<<" elements\n";
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    cout<<"Enter the element to be searched : ";
    cin>>key;
    int index=binary_search(a,n,key);
    cout<<index;
}