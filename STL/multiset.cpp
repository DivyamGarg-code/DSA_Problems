#include<bits/stdc++.h>
using namespace std;
typedef multiset<int>::iterator It;
// multiset that can store multiple elements that have same elements
// stored in a specific -> sorted according to internal comparision object
// values once inserted can't be modified
// associative container - elements are reffered by their value and not by their index
// underlying data structure is BST 
int main(){
    int arr[]={10,20,30,20,10,10,30,30,30,30,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    multiset<int> m(arr,arr+n);
    for(auto x:m){
        cout<<x<<" ";
    }
    cout<<endl;

    // erase 
    m.erase(20); // all the occurences of 20 will be erased
    for(auto x:m){
        cout<<x<<" ";
    }
    cout<<endl;
    // insert
    m.insert(40);

    // count
    cout<<m.count(10);

    // find
    auto it=m.find(30);
    cout<<*it<<endl;

    // get range all the elements that are equal to 30
    pair<It,It> range=m.equal_range(30);
    for(auto it=range.first;it!=range.second;it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto it=m.lower_bound(10);it!=m.upper_bound(77);it++){
        cout<<*it<<" ";
    }
}