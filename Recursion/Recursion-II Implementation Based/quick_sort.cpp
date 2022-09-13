#include<bits/stdc++.h>
using namespace std;
// Divide and conquer algorithm
// in avg case nlogn
// n worst case n^2
int partition(int a[],int s,int e){
    int cnt=0;
    for(int i =s+1; i <=e ; i++){
        if(a[s]>a[i]){
            cnt++;
        }
    }
    int k=s+cnt;
    swap(a[s],a[k]);
    int i=s;
    int j=e;
    while(i<cnt && j>cnt){
        if(a[i]<a[k]){
            i++;
        }else if(a[j]>a[k]){
            j--;
        }else{
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    return k;

}

void quick_sort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int pivot=partition(a,s,e); // will return the index
    cout<<pivot<<endl;
    quick_sort(a,s,pivot-1);
    quick_sort(a,pivot+1,e);
    
}


int main(){
    int a[]={10,9,8,7,6,5,3,2,1};
    int n=sizeof(a)/sizeof(a[0]);
    int s=0;
    int e=n-1;
    quick_sort(a,s,e);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}