#include<bits/stdc++.h>
using namespace std;

// Time complexity to build heap using heapify method is O(n)
// Time complexity O(nlogn)
/*
The merge sort is slightly faster than the heap sort for larger sets, but it requires twice the memory of the heap sort because of the second array.
*/
// basically this function takes the i_th element to its correct position
void heapify(int a[], int n, int i)  { 
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]>a[largest]){
        largest=left;
    }
    if(right<n && a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}

//Function to build a Heap from array.
void buildHeap(int a[], int n)  {  // Max heap root element will be the largest
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
}
//Function to sort an array using Heap Sort.
void heapSort(int a[], int n){
    buildHeap(a,n); 
    while(n>0){
        swap(a[0],a[n-1]); // step1. swap 1st maximum element with the last element
        n=n-1; //step2. decrement the size by 1
        heapify(a,n,0); // step3. place the first elementto its correct position
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    heapSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}