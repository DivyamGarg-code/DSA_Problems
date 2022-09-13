#include<bits/stdc++.h>
using namespace std;
// Genric Programmimg

// From templates you get the freedom from data type
template<typename T>
int search(T a[],int n,T key){
    for(int i = 0; i < n; i++){
        if(a[i]==key){
            return i;
        }
    }
    return n;
}
// If you want to perform searching in kind of array(any data type use template)
int main(){
    float a[]={10,20,30};
    int n=sizeof(a)/sizeof(a[0]);
    float key;
    cin>>key;
    cout<<search(a,n,key);
    return 0;
}