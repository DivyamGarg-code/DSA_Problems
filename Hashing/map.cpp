#include<bits/stdc++.h>
using namespace std;
/* Map is associative container that store values between the mapping pairs
 Maps - Map or Unordered Map
Operations :  
 insert(k,v) inserting a key value pair
 query(k)  | find(k) searching what is the price of that particular key
 delete(k) | erase(k) deleting that particular key
It is the self balancing BST and ordering is defined by the key 
Keys are ordered in maps and are unordered in unorderd maps.

IN MAPS AND MULTIMAPS ALL THE FUNCTIONS : INSERT,FIND,ERASE WORK IN Log(n) time because of 
underlying self balancing BST
UNORDERED MAP TAKES O(1) TIME ON AN AVERAGE TO INSERT,FIND,ERASE KEY VALUE PAIR
*/
int main(){
    map<string,int> m;
    // 1. Insert
    m.insert(make_pair("mango",100));

    pair<string,int> p;
    p.first="guava";
    p.second=120;
    m.insert(p);

    m["banana"]=50;
    // 2. Search
    string fruit;
    cin>>fruit;
    auto it=m.find(fruit);
    if(it!=m.end()){
        cout<<"price of "<<fruit<<" is "<<m[fruit]<<endl;
    }else{
        cout<<"fruit is not present\n";
    }
    // another way to find a particular map
    // it stores unique keys only once
    if(m.count(fruit)){
        cout<<"Price is "<<m[fruit]<<endl;
    }else{
        cout<<"not present\n";
    }
    // find function returns an iterator while count func returns an integer
    // auto -> map<string,int> :: iterator | it 

    // updating the price
    m[fruit]+=20;
    //3. erase
    m.erase(fruit);
    if(m.count(fruit)){
        cout<<"Price is "<<m[fruit]<<endl;
    }else{
        cout<<"not present\n";
    }
    
    m["litchi"]=30;
    m["apple"]=100;
    m["orange"]=60;

    // iterate over all key and value pairs | use (*it).first or it->first to access
    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<" and "<<it->second<<endl;
    }
    // for loop 
    // all the keys wil be in lexiographically sorted order
    for(auto p:m){
        cout<<p.first<<" : "<<p.second<<endl;
    }
    return 0;
}