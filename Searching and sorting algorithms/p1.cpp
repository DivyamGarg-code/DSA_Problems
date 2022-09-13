#include<bits/stdc++.h>
using namespace std;
// Time Complexity O(nlog(n)) all cases
void merge(int a[],int mid,int s,int e){
    int n1=mid-s+1;
    int n2=e-mid;
    int b[n1],c[n2];
    for(int i = 0; i < n1; i++){
        b[i]=a[s+i];
    }
    for(int i = 0; i < n1; i++){
        c[i]=a[mid+1+i];
    }
    int k=s;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(b[i]<=c[j]){
            a[k]=b[i];
            i++;
            k++;
        }else if(b[i]>c[j]){
            a[k]=c[j];
            j++;
            k++;
        }
    }
    while (i<n1){
        a[k]=b[i];
        i++;
        k++;
    }
    while (j<n2){
        a[k]=c[j];
        j++;
        k++;
    }
    
}

 void merge_sort(int a[],int s,int e){
    if(s<e){
        int mid=s+(e-s)/2;
        merge_sort(a,s,mid);
        merge_sort(a,mid+1,e);
        merge(a,mid,s,e);
    }
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
    int s=0;
    int e=n-1;
    merge_sort(a,s,e);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}