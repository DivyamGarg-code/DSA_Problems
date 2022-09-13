#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[],int n,int i=0){
    // Base case
    if(n==1){
        return;
    }
    if(i==n-1){
        return bubble_sort(a,n-1,0); // now you have to sort this part
    }
    if(a[i]>a[i+1]){
        swap(a[i],a[i+1]);
    }
    return bubble_sort(a,n,i+1);
}
int main(){
    int a[]={5,4,3,2,1};
    int n=sizeof(a)/sizeof(a[0]);
    bubble_sort(a,n);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}