#include<bits/stdc++.h>
using namespace std;
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
int main(){
    int n;
    cout<<"enter the size of array : ";
    cin>>n;
    int a[n];
    cout<<"enter the number of elements\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cout<<"enter the key : ";
    cin>>key;
    linear_search(a,key,n);
    return 0;
}