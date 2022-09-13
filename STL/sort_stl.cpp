#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b){
    return a>b;
}
// Let's understand how to pass a function as a parameter to another function
void bubble_sort(int a[],int n,bool (&cmp)(int a,int b)){
    for(int i = 1; i <=n-1; i++){
        for(int j = 0; j <= n-i-1; j++){
            if(cmp(a[j],a[j+1])){
                swap(a[j],a[j+1]);
            }
        }
    }
}
int main(){
    int n,key;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    // Sorting an array using sort function,more efficient in terms of time complexity
    sort(a,a+n,compare); // sending the compare function as a parameter
    
    bubble_sort(a,n,compare); // bubble sort using comparators
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}     