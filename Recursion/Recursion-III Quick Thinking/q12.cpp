#include<bits/stdc++.h> 
using namespace std; 
void printCombination(int arr[], int data[], int start, int end, int index, int r) 
{ 
  if(index == r) 
  { 
    for (int j = 0; j < r; j++) 
      cout << data[j] << " "; 
    cout << endl; 
    return; 
  } 
  for(int i = start; i <= end && end - i + 1 >= r - index; i++) 
  { 
    data[index] = arr[i]; 
    printCombination(arr, data, i+1, end, index+1, r); 
  } 
} 
int main() 
{ 
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
  }
  int r;
  cin>>r;
  int data[r]; 
  printCombination(a,data,0,n-1,0,r);
} 