#include<bits/stdc++.h>
using namespace std;
// set -> 2 types set/ordered  and unordered set
// set is the data structure used to store unique set of elements
// insertion,find and removal of elements take log(n) time
// you can't modify or upadate the values of set, for doing this you need to first delete that
// value and then insert the new value
int main(){
    int a[]={3,4,3,5,2,3,1,5,2,1,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    set<int> s;

    // INSERTION
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    // will print in the sorted order
    for(auto it=s.begin();it!=s.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
    // DELETION
    s.erase(3);
    for(auto p:s){
        cout<<p<<" ";
    }
    cout<<endl;
    // auto f=s.find(2);
    // s.erase(f);

    // set of pairs
    set<pair<int,int>> m;
    m.insert({10,1});
    m.insert({20,1});
    m.insert({10,5});
    m.insert({10,5});
    m.insert({20,-5});
    m.insert({20,100});
    m.insert({5,1});
    m.insert({5,3});
    m.erase(m.find(make_pair(5,3)));

    for(auto x:m){ // printed in sorted order
        cout<<x.first<<" and "<<x.second<<endl;
    }

// write {20,100} or make_pair(20,100)
    auto it=m.upper_bound({20,100});
    if(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
    }else{
        cout<<"It was the last number\n";
    }

    // Suppose you want to find out the key whose 1st element is >10
    // you can do this 
    auto it1=m.upper_bound(make_pair(10,INT_MAX));
    if(it1!=m.end()){
        cout<<it1->first<<" "<<it1->second<<endl;
    }else{
        cout<<"It was the last number\n";
    }
    
    return 0;
}