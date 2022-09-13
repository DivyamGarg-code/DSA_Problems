#include<bits/stdc++.h>
#include<D:/Users/a/Desktop/Algorithms/DSA_Problems/STL/q1.cpp>
using namespace std;

int main(){
    // Pair<int> p1; //You can pass any datatype which you want to get
    // p1.setX(4.345);
    // p1.setY(5);
    // cout<<p1.getX()<<" "<<p1.getY()<<endl;
    // Pair<double> p2;
    // p2.setX(4);
    // p2.setY(5.9083);
    // cout<<p2.getX()<<" "<<p2.getY()<<endl;
    // Pair<int,double> p1; // 2 data types can be passed
    // p1.setX(4.345);
    // p1.setY(5.43);
    // cout<<p1.getX()<<" "<<p1.getY()<<endl;
    
    // You can also create triplet let suppose 3 data types in this pair class int,double,char
    Pair<int,Pair<double,char>> p1;
    p1.setX(23);
    Pair<double,char> p4;
    p4.setX(2.45);
    p4.setY('A');

    p1.setY(p4); // here you have to pass the pair
    cout<<p1.getX()<<" "<<p1.getY().getX()<<" "<<p1.getY().getY();
    

}
