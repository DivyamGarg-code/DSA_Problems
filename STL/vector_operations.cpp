#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> d{1,2,3,4};

    // PushBack O(1) most of the time
    d.push_back(6);
    for(auto x:d){
        cout<<x<<" ";
    }
    cout<<endl;

    //Pop Back removes last element in O(1) time
    d.pop_back();
    for(auto x:d){
        cout<<x<<" ";
    }
    cout<<endl;

    // Insert some elements in the middle O(N) ie adding some elements and shifting the others
    d.insert(d.begin()+3,100);
    for(auto x:d){
        cout<<x<<" ";
    }
    cout<<endl;

    // If you want to add 4 elements having the value 100
    d.insert(d.begin()+3,4,100);
    for(auto x:d){
        cout<<x<<" ";
    }
    cout<<endl;

    // erase some element in the middle O(N)
    d.erase(d.begin()+2);
    for(auto x:d){
        cout<<x<<" ";
    }
    cout<<endl;

    d.erase(d.begin()+2,d.begin()+5); // if want to erase withen a range
    for(auto x:d){
        cout<<x<<" ";
    }
    cout<<endl;
    // vectors do not shrink its size even if erase operation is called
    cout<<d.capacity()<<endl; 
    d.resize(15); // if the size is increasing then more memory will be occupied by the array
    for(auto x:d){
        cout<<x<<" ";
    }
    cout<<endl;
    // d.clear();
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    return 0;
}