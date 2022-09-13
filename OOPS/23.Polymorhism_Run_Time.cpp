#include<bits/stdc++.h>
using namespace std;

/*
Run Time Polymorphism

Virtual Functions-Virtual Functions are those functions which are present in the base class and they are overriden in the derived class 
By adding the virtual keyword basically I am saying the compiler that please take the decision at runtime ke which print function is to be called. Check and make the decision at runtime

in vehicle car example we are checking to whom v2 is pointing and then making the decision ke kiska function call hoga

By using virtual functions we can achieve runtime polymorphism

Usecase
Let suppose we have an organization and we have to calculate the salary of it's employees 
Employee Categories:
Employee : HR(1),Managers(3),Engineers(20),Others(4)
Sabhi employees ki salary calculate karne ka formula different ha
*/

class Vehicle{
    public:
        virtual void print(){
            cout<<"Vehicle\n";
        }
};

class Car:public Vehicle{
    public:
        void print(){
        cout<<"Car\n";
        }
};
int main(){
    Vehicle *v2=new Car;
    v2->print();
    return 0;
}