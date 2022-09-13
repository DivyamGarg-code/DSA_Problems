#include<bits/stdc++.h>
using namespace std;

// EXAMPLE OF AN UNORDERED MAP TO GET THE MULTIPLE PHONENUMBER OF PARTICULAR PERSON
// IN O(1) TIME
// rahul : 84854.... 5858.... 4595995...
int main(){
    unordered_map<string,vector<int>> phonebook;
    phonebook["rahul"].push_back(856685);
    phonebook["rahul"].push_back(555985);
    phonebook["rahul"].push_back(83445);
    phonebook["rahul"].push_back(98685);
    phonebook["neha"].push_back(98685);
    phonebook["neha"].push_back(98685);
    phonebook["neha"].push_back(98685);
    phonebook["neha"].push_back(98685);
    for(auto x:phonebook){
        cout<<"Name: "<<x.first<<" -> ";
        for(auto y:x.second){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}