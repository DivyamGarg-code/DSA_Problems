
#include <bits/stdc++.h>
using namespace std;

// Merge Sort
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
    return;
 }

// Quick Sort
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

//Bubble Sort
// Here the worst case O(n^2)
void bubble_sort(int a[],int n){
    int is_swaped,cnt_comparisions=0; //this will optimize code for the best case when the array is already sorted
    // and make best case O(n)
    for(int i = 1; i <n; i++){ // n-1 times repeated and for each iteration it goes like n-1,n-2,..1 
        is_swaped=0;
        for(int j = 0; j <n-i; j++){ // which is n*(n-1)/2 
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

// selection sort Time complexitity--> O(n^2) in all the cases
void selection_sort(int a[],int n){
    for (int i = 0; i <n-1; i++){
        int min=i; // (This is index) considering 1st element to be min
        for (int j = i+1; j < n; j++){
            if(a[j]<a[min]){    
                min=j;
            }
        }
        if(min!=i){ // swap
            int t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
}

// Binary Search
// Best case O(1)
// Worst case O(logn) after each time search space is becoming half
int binary_search(int a[],int data,int start,int end){
    if(start<=end){
        int mid=start+(end-start)/2;
        if(a[mid]==data){
            return mid;
        }
        if(data<a[mid]){
            return binary_search(a,data,start,mid-1);
        }
        if(data>a[mid]){
            return binary_search(a,data,mid+1,end);
        }
    }
    return -1;
}

// linear search
// Best Case O(1)
// Worst case O(n)
// Avg case sum of all cases/total number of cases (1+2+3+....+n)/n ->(n+1)/2
void linear_search(int a[],int key,int size){
    int found =0;
    int i=0;
    for(; i < size; i++){
        if(a[i]==key){
            found=1;
            break;
        }
    }
    if(found==1){
        cout<<key<<" present at index "<<i;
    }else{
        cout<<key<<" not present";
    }
}

