#include<bits/stdc++.h>
using namespace std;
// Genric Programmimg

// forwardIterator This class will depend upon what kind of container we are using 
// work on different type of containers
// container could be array,vector,list,map .......anything
// Template + Iterators
template<class forwardIterator,class T>
forwardIterator search(forwardIterator start,forwardIterator end,T key){
    while(start!=end){
        if(*start==key){ // dereferencing the adress 
            return start;
        }
        start++;
    }
    return end;
}

int main(){
    float a[]={10,20,30};
    int n=sizeof(a)/sizeof(a[0]);
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    float key;
    cin>>key;
    auto it=search(l.begin(),l.end(),key); // l.begin() is of list<int>::iterator this particular data type
    if(it==l.end()){
        cout<<"Not Present";
    }else{
        cout<<*it;
    }
    
    return 0;
}