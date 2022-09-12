#include<bits/stdc++.h>
using namespace std;

//Define a comparator function
bool compare(int a,int b){ // optional
    return a<b;
}
int main(){
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
    int *a=new int[n];
    cout<<"Enter "<<n<<" elements\n";
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    //Sorting the array using the sort function sort()
    sort(a,a+n,compare);
    for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}
