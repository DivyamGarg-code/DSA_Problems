#include<bits/stdc++.h>
using namespace std;

int main(){
    // String init
    string s0;
    string s1("Hello");
    string s2="Hello World";
    string s3(s2);
    char a[]={'a','b','c','\0'};
    string s4(a);
    cout<<s0<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s4<<endl;

    // string is empty or not
    if(s0.empty()){
        cout<<"s0 is empty"<<endl;
    }
    
    //append
    s0.append("Hi buddy");
    cout<<s0<<endl;
    s0+=" How are you";
    cout<<s0<<endl;

    // remove
    cout<<s0.length()<<endl;;
    s0.clear();
    cout<<s0.length()<<endl;

    // compare the 2 strings lexographically - the editing or making of a dictionary or the principles and practices of dictionary making.
    s0="Apple";
    s1="Mango";
    cout<<s0.compare(s1)<<endl; //returns an int ==0 if both strings are equal, <0 or >0

    if(s1>s0){
        cout<<"s1 is lexo. greater than s0\n";
    }
    
    cout<<s1[0]<<endl;

    // Find substrings
    string s="I want an apple juice";
    int idx=s.find("apple");
    cout<<idx<<endl;
    
    // remove a word 
    string b="apple";
    cout<<"before erasing : "<<s<<endl;
    s.erase(idx,b.length()+1);
    cout<<"after erasing : "<<s<<endl;

    // iterators [begin,end) it->pointer auto _.set the datatype dynamically
    for (auto it=s.begin();it<s.end(); it++){
        cout<<(*it);
    }
    cout<<endl;
    for(auto c:s1){
        cout<<c;
    }
    

}