// Problem Name: Book Allocation Problem
// Problem Difficulty: 3
// Problem Constraints: 1 < t < 50 <br>
// 1< n < 100 <br>
// 1< m <= 50 <br>
// 1 <= A<sub>i</sub> <= 1000
// Problem Description:
// You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

// Input Format: First line contains integer t as number of test cases.
// Next t lines contains two lines. 
// For each test case, 1st line contains two integers n and m which represents the number of books and students and 2nd line contains n space separated integers which represents the number of pages of n books in ascending order.
// Sample Input: 1
// 4 2
// 12 34 67 90
// Output Format: Print the maximum number of pages that can be assigned to students. 

// Sample Output: 113 


// =====Solution=====
// C++ program for optimal allocation of pages
#include<bits/stdc++.h>
//#include"/Users/codingblocks/Documents/All Code/stdc++.h"
#include<iostream>
using namespace std;

bool isValid(int a[],int n,int k,int mx){ // mx -> maximum number of pages
    int student=1;
    int sum=0;
    for(int i = 0; i < n; i++){
        sum=sum+a[i];
        if(sum>mx){ 
            student++; // start assigning the book to the new student
            sum=a[i];
        }
        if(student>k){
            return false;
        }

    }
    return true;

}
// Drivers code
int main()
{
    // n -> no. of books  k -> no. of students
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int j=0;j<n;j++){
        cin>>arr[j];
    }
    // corner case
    if(k>n){ // if no. of students > no. of books
        return 0;
    }
    int max_element=arr[0];
    for(int i = 1; i < n; i++){
        max_element=max(max_element,arr[i]);
    }
    int sum=0;
    for(int i = 0; i < n; i++){
        sum+=arr[i];
    }
    int start=max_element;
    int end=sum;
    int result=-1; // if is not possible to allocate the books
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isValid(arr,n,k,mid)==true){
            result=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }

    }
    cout<<result;

	return 0;
}
