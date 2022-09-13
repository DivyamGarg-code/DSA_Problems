#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={20,30,40,40,40,50,110,110};
    int n=sizeof(arr)/sizeof(arr[0]);
    // search in sorted array
    int key;
    cin>>key;
    bool present=binary_search(arr,arr+n,key);
    if(present){
        cout<<"present";
    }else{
        cout<<"not present";
    }
    cout<<endl;
    // 2 more things
    // To get the index of element

// V.V.V IMP lower_bound (s,e,key) upper_bound (s,e,key) // these functions work in O(logn) time

    // auto is the adress of bucket inside the array |  |  |  |
    // let key =40
    auto lb=lower_bound(arr,arr+n,key); // returns the adress of  first value which is >=40 in the array
    auto ub=upper_bound(arr,arr+n,key); // returns the adress of  first value which is (strictly greater than) >40 in the array
    if(present){
        cout<<"lower bound of "<<key<<" is "<<(lb-arr)<<endl;
        cout<<"upper bound of "<<key<<" is "<<(ub-arr)<<endl;
        cout<<"occurance frequency of "<<key<<" is "<<(ub-lb)<<endl;
    }else{
        cout<<"not present"<<endl;
    }
    return 0;
}       