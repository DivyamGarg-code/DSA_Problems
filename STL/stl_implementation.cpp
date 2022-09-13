#include<bits/stdc++.h>
using namespace std;

// This is how STL works
/*
Templates give you freedom from the underlying data type
Iterators give you freedom from the containers
Comparators give you freedom from different type of operations operating on data
*/
// Genric Programmimg Template
// forwardIterator This class will depend upon what kind of container we are using 
// work on different type of containers
// container could be array,vector,list,map .......anything

// Template + Iterators+ Comparators
template<class forwardIterator,class T,class Compare>
forwardIterator search(forwardIterator start,forwardIterator end,T key,Compare cmp){
    while(start!=end){
        if(cmp(*start,key)){ // dereferencing the adress 
            return start; 
        }
        start++;
    }
    return end;
}
class Book{
    public:
        string name;
        int price;
        Book(string name,int price){
            this->name=name;
            this->price=price;
        }

};

class BookCompare{
    public:
        bool operator()(Book A,Book B){
            if(A.name==B.name){
                return true;
            }
            return false;
        }

};
int main(){
    Book b1("C++",100); // old edition
    Book b2("Python",120);
    Book b3("Java",130);
    Book b4(b1);
    list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);
    Book booktofind("C++",230); // new edition
    BookCompare cmp;
    list<Book>::iterator it=search(l.begin(),l.end(),booktofind,cmp);
    // or auto it=search(l.begin(),l.end(),booktofind,cmp);
    if(it!=l.end()){
        cout<<"Same Book is present in the library"<<endl;
    }else{
        cout<<"Same book not present";
    }
    // if(cmp(b1,booktofind)){
    //     cout<<"Same books ";
    // }
    for(auto it:l){
        cout<<it.name<<" "<<it.price<<endl;
    }
    return 0;
}