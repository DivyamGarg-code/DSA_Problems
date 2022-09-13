#include<bits/stdc++.h>
using namespace std;

// multiset custom class

class person_compare{
    public:
        bool operator()(pair<string,int> p1,pair<string,int> p2){
            return p1.second<p2.second;
        }
};
int main(){
    pair<string,int> p1=make_pair("B",100);    
    pair<string,int> p2=make_pair("A",40);    
    pair<string,int> p3=make_pair("C",120);    
    pair<string,int> p4=make_pair("D",10);    

    // Multiset

    // Pair - Name(string),Money(int)

    // Custom Data type
    multiset<pair<string,int>,person_compare> m; 
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);
    // elements will be printed inlexographical order acc. to x.first
    for(auto x:m){
        cout<<x.first<<" "<<x.second<<endl; 
    }
    // suppose you want to sort them acc. to x.second
    return 0;
}