#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int s,int mid,int e){
    int n1=mid-s+1;
    int n2=e-mid;
    int b[n1],c[n2];
    for(int i = 0; i <n1; i++){
        b[i]=a[s+i];
    }
    for(int i = 0; i < n2; i++){
        c[i]=a[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=s;
    while(i<n1 && j<n2){
        if(b[i]<=c[j]){
            a[k]=b[i];
            i++;
            k++;
        }else{
            a[k]=c[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        a[k]=b[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=c[j];
        j++;
        k++;
    }
}

void merge_sort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    merge_sort(a,s,mid);
    merge_sort(a,mid+1,e);
    merge(a,s,mid,e);
}


int main(){
    int a[]={10,9,8,7,6,5,3,2,1};
    int n=sizeof(a)/sizeof(a[0]);
    int s=0;
    int e=n-1;
    merge_sort(a,s,e);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}