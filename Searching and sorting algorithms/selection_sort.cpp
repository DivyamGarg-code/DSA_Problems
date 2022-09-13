// selection sort Time complexitity--> O(n^2) in all the cases
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cout<<"enter the size of array\n";
    cin>>n;
    int a[n];
    cout<<"enter the elements : ";
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }

    for (int i = 0; i <n-1; i++){
        int min=i; // (This is index) considering 1st element to be min
        for (int j = i+1; j < n; j++){
            if(a[j]<min){ // swap
                min=j;
            }
        }
        if(min!=i){ // swap
            int t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
    cout<<"after sorting\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }

    
    
    
    return 0;
}