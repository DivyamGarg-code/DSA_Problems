
#include <bits/stdc++.h>
using namespace std;
// insertion sort --> insert an element from an unsorted array to its correct position in the sorted array 
//Time compexity --> worst case O(n^2)  best case O(n)
void insertion_sort(int a[],int n){
    for (int i = 1; i <n; i++){
        int current=a[i];
        int j=i-1;
        while(a[j]>current && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=current;
    }
}
int main(){
    int n;
    cout<<"enter the size of array\n";
    cin>>n;
    int a[n];
    cout<<"enter the elements : ";
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    insertion_sort(a,n);
    cout<<"after sorting\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
}