// RECURSIVE APPROACH

#include <bits/stdc++.h>
using namespace std;
// Here the worst case O(n^2)
void bubble_sort(int a[],int n){
    int is_swaped,cnt_comparisions=0; //this will optimize code for the best case when the array is already sorted
    // and make best case O(n)
    for(int i = 1; i <n; i++){ // n-1 times repeated and for each iteration it goes like n-1,n-2,..1 
        is_swaped=0;
        for(int j = 0; j <=n-i-1; j++){ // which is n*(n-1)/2 
            cnt_comparisions+=1;
            if(a[j]>a[j+1]){
                //swap;
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                is_swaped=1;
            }
        }
        if(is_swaped==0){
            break;
        }
    }
    cout<<"no. of comparisions -> "<<cnt_comparisions<<endl;
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
    bubble_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}