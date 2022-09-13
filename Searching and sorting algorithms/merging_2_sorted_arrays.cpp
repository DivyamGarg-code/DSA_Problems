// Merging 2 sorted arrays;
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n1,n2;
    cout<<"enter the size of 2 sorted arrays\n";
    cin>>n1>>n2;
    int a[n1],b[n2]; // 2 sorted arrays
    cout<<"enter "<<n1<<" elements of 1st sorted array : ";
    for (int i = 0; i < n1; i++){
        cin>>a[i];
    }
    cout<<"enter "<<n2<<" elements of 2nd sorted array : ";
    for (int i = 0; i < n2; i++){
        cin>>b[i];
    }
    int n=n1+n2;
    int x[n];
    int i=0,j=0,k=0;
    while(i<=n1-1 && j<=n2-1){
        if(a[i]<=b[j]){
            x[k]=a[i];
            i++;
            k++;
        }else{
            x[k]=b[j];
            j++;
            k++;
        }
    }
    for(int p=i;p<=n1-1;p++){
        x[k]=a[i];
        i++;
        k++;
    }
    for(int p=j;p<=n2-1;p++){
        x[k]=b[j];
        j++;
        cout<<x[k]<<" ";
        k++;
    }
    cout<<"\n";
    cout<<"after sorting\n";
    for (int l = 0; l < n; l++)
    {
        cout<<x[l]<<" ";
    }
    
    
    return 0;
}