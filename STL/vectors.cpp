#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a;
    vector<int> b(5,10); // 5 integers with the value 10
    vector<int> c(b.begin(),b.end()); // copy all the elements of vector b in vector c
    vector<int> d{1,2,3,4,5};
    // Look how we can iterate over the vector
    for(int i = 0; i < c.size(); i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    for(auto it=b.begin();it!=b.end();it++){ // Here auto -> vector<int>::iterator
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto x:d){ // for every int x that lies in vector d
        cout<<x<<" ";
    }
    cout<<endl;
    vector<int> v;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int no;
        cin>>no;
        v.push_back(no);// Addition at the end this basically doubles the memory if reqd.
        cout<<"changing capacity "<<v.capacity()<<endl; // doubling memory is an expensive operation
    }
    // To avoid doubling we use reserve function
    // eg. v.reserve(1000) capacity will change only after 1000 elements got filled This will avoid the more time being taken



    // understand at memory level,what are the differences between 2
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl; // size of the underlying array as when we use push_back doubles the memory when required
    cout<<v.max_size()<<endl; // maximum no. of elements a vector can hold in the worst case acc. to the available memory in the library

    cout<<d.size()<<endl;
    cout<<d.capacity()<<endl;
    cout<<d.max_size()<<endl;

    return 0;
}