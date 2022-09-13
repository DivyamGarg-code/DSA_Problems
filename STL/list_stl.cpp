#include<bits/stdc++.h>
using namespace std;
// list<data_type> l eg l.sort()....
/*
front,back,sort reverse,remove,pop_front.pop_back,push_front.push_back, erase & insert using iterators
*/
void print(list<string> l){
    for(auto x:l){
        cout<<x<<" ";
    }
    cout<<endl;
}
int main(){
    list<int> l;
    // Init
    list<int> l1{1,2,3,4};
    list<string> l2{"apple","mango","lichi"};
    l2.push_back("orange");

    //sort
    l2.sort();

    //reverse
    l2.reverse();
    cout<<l2.front()<<endl;
    l2.pop_front();
    l2.push_back("mango");
    for(auto x:l2){
        cout<<x<<" ";
    }
    cout<<endl;

    // Using iterators 
    for(auto it=l2.begin();it!=l2.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;

    // remove a fruit
    string s;
    cin>>s;
    l2.remove(s);
    for(auto it=l2.begin();it!=l2.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
    l2.push_back("guava");
    print(l2);
    
    // erase one or more elements
    auto it=l2.begin(); // you cant do l2.begin()+3 as the elements are not stored in linear memory
    it++; // it will take the pointer to the next node
    it++;
    l2.erase(it);
    print(l2);

    // we can insert elements in the list
    it=l2.end();
    l2.insert(it--,"fruit");
    print(l2);
    return 0;
}