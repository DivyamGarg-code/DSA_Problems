// Problem Name: PIVOT OF SORTED AND ROTATED ARRAY
// Problem Description:
// You are given a sorted but rotated array. You need to fine the index of the pivot element of the array where pivot is that element 
//in the array which is greater than its next element and divides the array into two monotonically increasing halves.

// Input Format: The first line denotes N - the size of the array. The following N lines each denote the numbers in the array.
// Sample Input: 5
// 4
// 5
// 1
// 2
// 3
// Output Format: Output the index of the pivot of the array.
// Sample Output: 1

// Time complexity O(logn)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[s]<=a[mid]){ // mid lying in 1st part
            if(a[mid]>a[mid+1]){
                cout<<mid;
                break;
            }else{
                s=mid+1;
            }
        }else if(a[mid]<=a[e]){
            if(a[mid]<a[mid-1]){
                cout<<mid-1;
                break;
            }else{
                e=mid-1;
            }
        }
    }
    return 0;
}