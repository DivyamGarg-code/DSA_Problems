#include<bits/stdc++.h>
using namespace std;
/*
a angry
b batman
b boat
c cat
c cold
c carpet
c cute
d dog
e elephant
*/
int main(){
    multimap<char,string> m;

    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        char ch;
        string s;
        cin>>ch>>s;
        m.insert(make_pair(ch,s));        
    }
    auto it=m.begin();
    m.erase(it);
    //print the entire map
    for(auto p:m){
        cout<<p.first<<" -> "<<p.second<<endl;
    }
    cout<<endl;
    // auto it1=m.lower_bound('b'); //batman
    // auto it2=m.upper_bound('b'); //elephant
    // for(auto it=it1;it!=it2;it++){
    //     cout<<it->second<<endl;
    // }
    // search for cat
    // auto f=m.find('c');
    // if(f->second=="cold"){
    //     m.erase(f);
    // }
    auto it1=m.lower_bound('c'); 
    auto it2=m.upper_bound('c'); 
    for(auto it=it1;it!=it2;it++){
        if(it->second=="cold"){
            m.erase(it);
            break;
        }
    }
    cout<<endl;
    for(auto p:m){
        cout<<p.first<<" -> "<<p.second<<endl;
    }
    return 0;
}