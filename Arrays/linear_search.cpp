#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,key;
    cout<<"Enter the size of array\n";
    cin>>n;
    int *a=new int[n];
    cout<<"Enter "<<n<<" elements\n";
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    cout<<"Enter the element to be searched\n";
    cin>>key;
    for (int i = 0; i < n; i++){
        if(key==a[i]){
            cout<<"Element is present at index "<<i;
            return 0;
        }
    }
    cout<<"Element not present\n";
    
    
}