#include<bits/stdc++.h>
using namespace std;
// find(): Searches for a particular element and returns the iterator pointing to the element if the element is found otherwise 
// it will return the iterator returned by end(). Its time complexity is O(logN) where N is the size of the set.
int main(){
    int arr[]={1,2,13,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    // Search --> find
    int key;
    cin>>key;
    // it is basically iterator
    auto it=find(arr,arr+n,key); // returns the adress of that key in the array
    int index=it-arr; // subtract the adress you'll get the value of idx
    if(index==n){
        cout<<"key not present";
    }else{
        cout<<"key present at index "<<index;
    }
    return 0;
}