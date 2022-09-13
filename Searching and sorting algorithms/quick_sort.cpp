#include <bits/stdc++.h>
using namespace std;

// Time complexity best/avg case O(nlogn)
// in worst case O(n^2)
// void swap(int *a,int *b){
//     int *t=a;
//     a=b;
//     b=t;
// }

int partition(int a[],int s,int e){
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(a[s]>=a[i]){
            cnt+=1;
        }
    }
    int k=s+cnt; // correct position of that element-->index
    int temp=a[s]; // for swapping
    a[s]=a[k];
    a[k]=temp;
    // swap(a[s],a[k]);
    int i=s;
    int j=e;
    while(i<k && j>k){
        if(a[i]<=a[k]){ // if not true move to next
            i++;
        }else if(a[j]>a[k]){ // if not true move to next
            j--;
        }else{
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
            // swap(a[i],a[j]);
            j--;
            i++;
        }
    }
    return k;

}
void quicksort(int a[],int s,int e){
    if(s<e){
        int pivot; // correct position of that element-->index
        pivot=partition(a,s,e); // this will give me the correct position of 1 element
        quicksort(a,s,pivot-1);
        quicksort(a,pivot+1,e);
    }
    return;
    
}



int main(){
    int length;
    cin>>length;
    int *a=new int[length];
    for (int i = 0; i < length; i++)
    {
        cin>>a[i];
    }
    int s=0; // starting index of the array
    int e=length-1; // this is the ending index of the array

    quicksort(a,s,e);

    for(int i=0;i<length;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}