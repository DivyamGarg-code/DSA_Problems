#include<bits/stdc++.h>
using namespace std;

int main(){
    // Pair
    pair<int,char> p;
    p.first=10;
    p.second='A';

    // Another way
    pair<int,char> P1(p);
    cout<<P1.first<<endl;
    cout<<P1.second<<endl;

    pair<int,string> p3=make_pair(100,"Audi");

    int a,b;
    cin>>a>>b;
    pair<int,int> p4=make_pair(a,b);
    // Array of pairs
    // vector of pairs
    // pair of pairs
    pair<pair<int,int>,string> car;
    car.first.first=10;
    car.first.second=20;
    car.second="Audi";
    

    return 0;
}     