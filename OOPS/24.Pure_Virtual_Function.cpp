#include<bits/stdc++.h>
using namespace std;

/*
MUST READ : https://www.geeksforgeeks.org/difference-between-virtual-function-and-pure-virtual-function-in-c/

Pure Virtual Functions
Any Class containing pure virtual functions can be known as abstract class

We can't make the object of abstract class

Pure virtual function example-
virtual void print()=0;
*/

class Vehicle{
    public:
        string color;
        virtual void print()=0;
}; // You can't create the object of this class

/* 
Now whenever the derived/child class inherit any abstract class then this class has 2 options
-implement all the pure virtual functions:ie jitne bhi virtual functions present the base class main un sabki definations ko complete kar do 
-other option left is ke hmari child class bhi abstract class bn jaygi

UseCase:
eg Employee ki salary calculate karni ha using formula CalculateSalary but the problem is ke different employee category salary's are calculated using different formula so we cant calculte the salary in the employee class as it is depending on the type of employee So ideally this CalculateSalary Function should be pure virtual function as we can't give the it's defination in the employee class itself,in such a case it's derived classes can only decide the salary of employees of different type 

Whenever we want to enforce our child class to create the functions of base class we basically make the function pure virtual in the base class so that if that function is created in the child class it could be accessable otherwise if we not make that function it will also make our child class as abstract 
*/
class Car:public Vehicle{
    public:
        int numGears;
        void print(){
            cout<<"Car\n";
        } 
};

int main(){
    Car c;
    c.print();
    return 0;
}