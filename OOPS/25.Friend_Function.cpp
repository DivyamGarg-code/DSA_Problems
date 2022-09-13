#include<bits/stdc++.h>
using namespace std;

/*
Friend Functions
Basically if you want to give access of private properties of a class to another class then by declaring another class as friend class we can give access to the private properties also  

Friend Functions Don't have the access to the this-> pointer as they are not member functions of that class

Friend functions can be put into any access modifier of the class : no effect will be seen
*/

class Bus{
    public:
        void print();// Here you cant give the defination you need to give defination outside class
};
void test();
class Truck{
    private:
        int x;
    protected:
        int y;
    public:
        int z;
    friend void Bus::print(); // You are giving access of all the properties of Truck to the bus->print function 
    friend void test();

    // friend class Bus; Now every member/function of bus class can have the access to all the properties of Truck class 
     
};

void Bus::print(){
    Truck t;
    t.x=10;
    t.y=20;
    t.z=30;
    cout<<t.x<<" "<<t.y<<" "<<t.z<<endl;
}
void test(){
    // Access Truck Private Properties
    Truck t;
    t.x=30;
    cout<<t.x<<endl;
}
int main(){
    Bus b;
    b.print();
    test();
    return 0;
}