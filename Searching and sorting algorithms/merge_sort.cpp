// merge sort algorithm with time complexity O(nlog(n)) and space complexity O(n)

#include <iostream>
using namespace std;
void merge(int a[],int mid,int s,int e){
    int n1=mid-s+1;
    int n2=e-mid;
    int b[n1],c[n2];
    for (int i = 0; i < n1; i++){
        b[i]=a[s+i];
    }
    for (int i = 0; i < n2; i++){
        c[i]=a[mid+1+i];
    }
    int i=0,j=0,k=s;
    while(i<=n1-1 && j<=n2-1){
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
    for(int p=i;p<=n1-1;p++){
        a[k]=b[i];
        i++;
        k++;
    }
    for(int p=j;p<=n2-1;p++){
        a[k]=c[j];
        j++;
        k++;
    }
}
void mergeSort(int a[],int size,int s=0,int e=0,int b=1){
    if(size==0 || size==1){
        return;
    }
    if(b==1){
        s=0;
        e=size-1;
        b=0;
    }
    if(s<e){
        int mid=(s+e)/2;
        mergeSort(a,size,s,mid,b); // will give me 1st sorted array
        mergeSort(a,size,mid+1,e,b); // will give me 2nd sorted array
        merge(a,mid,s,e);
    }

}


int main(){
    int length;
    cin >> length;
    int* input = new int[length];
    for(int i=0; i < length; i++){
         cin >> input[i];
    }
    mergeSort(input, length);
    for(int i = 0; i < length; i++) {
        cout << input[i] << " ";
    }
}